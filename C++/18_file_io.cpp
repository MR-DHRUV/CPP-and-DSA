#include <iostream>
#include <fstream>

using namespace std;

// the usefull classes for working with files are
// 1 fstreambase
// 2 ifstream
// 3 ofstream

// to work with files in cpp, there are two ways to open a file
// 1 using constructor
// 2 using member function open() of the class

int main()
{
    string toWriteinFile = "Harry op";

    // opening using constructor to write it using fstram as i want to give output to file
    ofstream myFile("18_sample.txt");

    // it will write "toWriteinFile" in that file
    myFile << toWriteinFile;

    // istream as i want to take input from file
    ifstream justFile("18_1_sample.txt");

    string dataFromFile;

    // this will copy only first word of file data to this string
    // justFile >> dataFromFile;
    // cout << dataFromFile << endl;

    string completedata;

    // to get complete line
    getline(justFile,completedata);
    cout << completedata << endl;


    return 0;
}