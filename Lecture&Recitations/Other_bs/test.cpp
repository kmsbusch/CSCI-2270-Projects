#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


int main(void)
{
	
	int m=1, n=2;
	int *pm&m, *pn=n, *r;
	r=pn;
	pn=pm;
	*pm=*pn+2;
	cout << "," << n << "," << *r << "," << *pm << endl;

	
	// string fileName = "testfile.txt";
	// string line = "";

	// ifstream myfile;
	// myfile.open(fileName);

	// getline(myfile, line);
	// stringstream ss(line);

	// string tmp, tmp1;
	// ss >> tmp >> tmp1;

	// cout << tmp << " " << tmp1;

	// return 0;

	// string line = "a line of text to iterate through";
	// string word;

	// istringstream iss(line, istringstream::in);

	// while( iss >> word )     
	// {
	// 	// Do something on `word` here...
	// 	cout << word << endl;
	// }

}