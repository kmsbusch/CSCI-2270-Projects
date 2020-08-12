#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define filename "testFile.txt"
//declare struct
struct PhoneContact 
{
    string name, nickName;
    int number;
    bool block;
} globalStruct1, globalStruct2;

int main(int argc, char* argv[])
{
    // char A[4] = {'H', 'I', '!', NULL};
    // int X[4] = {0, 1, 2, 3};

    // cout << *A << endl;
    // cout << *X << endl; 
    
    //Declare a local instance of PhoneContact
    PhoneContact localStruct;
    //initialize struct data
    localStruct.name = "Christopher";
    localStruct.nickName = "Chris";
    localStruct.number = 42;
    localStruct.block = false;

    cout << localStruct.name << endl;
    cout << localStruct.nickName << endl;
    cout << localStruct.number << endl;
    cout << localStruct.block << endl;

//     // initialize input stream object
//     ifstream fs;
//     // filename is defined above in the defined statemaent
//     fs.open(filename);
//     string line;
//     getline(fs, line);
//     cout << line;
	string fileName = "NULL";
	if (argc < 1) 
    {
        cout << "Not enough arguments" << endl;
        return -1;

    }
    else //argv[1] should be the filename
    {
		fileName = argv[1];
	}
	
	ifstream fs;
	fs.open(fileName);
	string line;
	// PhoneContact phoneBook[4];
	// while(!fs.eof())
	// {
	// 	getline(fs, line, ',');
	// 	cout << line << endl;




	// }
	
}
