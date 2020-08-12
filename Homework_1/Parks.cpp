// CS2270 Fall 2019
// Author: Kevin Busch
// Homework 1
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


struct Park
{
    string parkname;
    string state;
    int area;
};

//Number of items currently stored in the array
void addPark (Park parks[], string parkname, string state, int area, int length)
{
    Park park;
    park.parkname = parkname;
    park.state = state;
    park.area = area;
    parks[length] = park;
}

void printList(const Park parks[], int length)
{
    for (int i = 0; i < length; i++)
    {
        Park park;
        park = parks[i];
        std::cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << std::endl;
    }
}

int main(int argc, char* argv[]) //not sure if these arguments are right or not. 
{
    ifstream fs;
    string line = "";
    int k = 0;
    int i = 0;
    string fileName;
    string outputFile = argv[2];
    float areaVal = stof(argv[3]);
    Park parks[100];
    Park allParks[100];
    if (argc < 3)
    {
        cout << "Not enough arguments" << endl;
        return -1;
    }
    // else if (argc > 3)
    // {
    //     cout << "Too many arguments" << endl;
    // }
    else
    {
        fileName = argv[1];
        fs.open(fileName);
        if (fs.is_open())
        {
            while (getline(fs, line))
            {
                if (line.length() != 0)
                {
                    //setting the stringstream to have line in it
                    stringstream ss(line);
                    Park park;
                    
                    
                    getline(ss, park.parkname, ',');
                    getline(ss, park.state, ',');
                    
                    string parkArea;
                    getline(ss, parkArea, ',');
                    park.area = stof(parkArea);

                    addPark(allParks, park.parkname, park.state, park.area, i);
                    i++;

                    if (park.area > areaVal)
                    {
                        addPark(parks, park.parkname, park.state, park.area, k);
                        ofstream myfileout;
                        myfileout.open(outputFile, ios_base::app); //might need to use argument variable thing here or something
                        myfileout << parks[k].parkname << "," << parks[k].state << "," << parks[k].area << endl; //line needs to be replace by parks stuff
                        k++;
                        myfileout.close();
                    }
                }
            }

            printList(allParks, i);
        }
    }
    
}