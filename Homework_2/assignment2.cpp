// CS2270 Fall 2019
// Author: Kevin Busch
// Homework 2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;




struct wordItem
{
	string word;
	int count;
};

void resize(wordItem *&arrayPtr, int &capacity) //wordItem was int before
{
	// TODO increase the capacity by two times
	int newCapacity = capacity * 2;
  // cout<<"Resizing from "<<capacity<<" to "<<newCapacity<<endl;

	// TODO dynamically allocate an array of size newCapacity
	wordItem *newArray = new wordItem[newCapacity];

	// TODO copy all data from oldArray to newArray
	for (int i = 0; i < capacity; i++)
	{
		newArray[i] = arrayPtr[i];
	}
	// TODO free the memory associated with oldArray
	delete [] arrayPtr;


	arrayPtr = newArray;
	capacity = newCapacity;

}

//i made this
void addWord(wordItem words[], string wordName, int count, int length)
{	
	wordItem item;
	item.word = wordName;
	item.count += count; 
	words[length] = item;
}

//and this

void getStopWords(char *ignoreWordFileName, string ignoreWords[]) //there's a semicolon here in the writeup, not sure why
{
	ifstream fs;
	//string fileName = *ignoreWordFileName; //ask prof
	//string ignoreWords[50];
	string line = "";
	int i = 0;


	fs.open(ignoreWordFileName);
	if (fs.is_open())
	{
		while  (getline(fs, line))
		{
			if (line.length() !=  0)
			{
				ignoreWords[i] = line;
				i++;
			}
		}
	}	
	else
	{
		cout << "Failed to open " << ignoreWordFileName << endl;
	}
	
	
}

bool isUniqueWord(string word, wordItem words[], int length)
{
	//wordItem item;
	for (int i = 0; i < length; i++)
	{
	string compare = words[i].word;
		if (compare == word)
		{
			return false;
		}
	}
	return true;
}

bool isStopWord(string word, string ignoreWords[])
{
    int i = 0;
    string compare = ignoreWords[0];
	while (i < 50)
	{
		i++;
		if (compare == word)
		{
		    return true;   
		}
		if (i == 50 && compare != word)
		{
		    return false; 
		}
		if (i < 50)
		{
		   compare = ignoreWords[i]; 
		}
		
	}	
	
}
int findWord(string word, wordItem words[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (word == words[i].word)
		{
			return i;
		}
	}
	return -1;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		count += uniqueWords[i].count;
	}
	return count;
}

void arraySort(wordItem uniqueWords[], int length)
{
	// int temp;
	for (int i = 0; i < length; i++)
	{
		int max = i;
		for (int k = i + 1; k < length; k++)
		{
			if (uniqueWords[k].count > uniqueWords[max].count)
			{
				max = k;
			}
		}
		wordItem temp;
		temp = uniqueWords[i];
		uniqueWords[i] = uniqueWords[max];
		uniqueWords[max] = temp;
		
	}
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords)
{
	cout << fixed << setprecision(4);
	float probabilityWords[10];
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		probabilityWords[k] = (float)uniqueWords[N+i].count / totalNumWords;
		cout << probabilityWords[k] << " - " << uniqueWords[N+i].word << endl;
		k++;
	}

}

int main(int argc, char* argv[])
{
	if (argc < 4 || argc > 4)
	{
		cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWords>" << endl;
	}
	else
	{
		ifstream fs;
		string ignoreWords[50];
		int counter = 0;
		int capacity = 100;
		wordItem word;
		wordItem *arrayPtr;
		arrayPtr = new wordItem[capacity];
		int numOfDoubles = 0;
		int indexEntered = stoi(argv[1]);
		string fileName = argv[2];
		string line = "";
		string temp;
		getStopWords(argv[3], ignoreWords);


		fs.open(fileName);
		if (fs.is_open())
		{ 
			while(fs >> line)
			{
				stringstream ss(line);
				getline(ss, temp, ' ');
				if (counter == capacity)
				{
					resize(arrayPtr, capacity);
					numOfDoubles++;
				}
				if (!(isStopWord(temp, ignoreWords)))
				{
					//cout << temp << endl;
					if (!(isUniqueWord(temp, arrayPtr, counter)))
					{
						int index = findWord(temp, arrayPtr, counter);
						if (index >= 0)
						{
							arrayPtr[index].count++;
							//cout << "im a massive fucking headass" << endl;
						}
					}
					else
					{
						word.word = temp;
						word.count = 1;
						arrayPtr[counter] = word;
						counter++;
						//cout << arrayPtr[counter].word << endl;
					}
					//counter++;
				}
			}
			int numNonStopWords = getTotalNumberNonStopWords(arrayPtr, counter);
			cout << "Array doubled: " << numOfDoubles << endl;
			cout << "#" << endl;
			cout << "Unique non-common words: " << counter << endl;
			cout << "#" << endl;
			cout << "Total non-common words: " << numNonStopWords << endl;
			cout << "#" << endl;
			cout << "Probability of next 10 words from rank " << indexEntered << endl;
			cout << "---------------------------------------" << endl;
			
			arraySort(arrayPtr, counter);
			printNext10(arrayPtr, indexEntered, numNonStopWords);
		}
	}
}