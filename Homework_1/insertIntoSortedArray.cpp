// CS2270 Fall 2019
// Author: Kevin Busch
// Homework 1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;




int insertintoSortedArray(int myArray[], int numEntries, int newValue)
{
    int temp;
    for (int i = 0; i < numEntries; i++)
    {

        if (myArray[i] > newValue)
        {
            temp = myArray[i];
            myArray[i] = newValue;
            newValue = temp;
        }
         
    }
    myArray[numEntries] = newValue;
    numEntries++;
    return (numEntries);
}



int main(int argc, char* argv[])
{
    ifstream myfile;
    
    string line = "";
    int i = 0;
    int numbers[100];
    // string filename = "NULL";
    if (argc < 1) 
    {
        cout << "No file entered" << endl;
        return -1;

    }
    else //argv[1] should be the filename
    {
        string fileName = argv[1];
        myfile.open(fileName);
        if(myfile.is_open())
        {
            while (getline(myfile, line))
            {
                string ans = "";
                if (line.length() != 0)
                {
                    //cout << line << endl;
                    i = insertintoSortedArray(numbers, i, stoi(line));
                }
                
                //cout << numbers[0];
                for (int k = 0; k < i; k++)
                {
                    ans = ans + to_string(numbers[k]) + ",";
                }
                cout << ans.substr(0, ans.length()-1) << endl;
                
            }
            

        }
        else
        {
            cout << "Failed to open the file." << endl; 
        }
    }
    //fileReader("numbers.txt");
}