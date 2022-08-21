#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream myFile1("18_sample.txt");

    string name;
    cout<<"Enter your name : ";
    cin>>name;

    // only one word is saved
    myFile1<<name;
    cout<<"Data saved to file"<<endl;

    //closing a file
    myFile1.close();


    ifstream myFile2("18_sample.txt");
    string content;

    myFile2>>content;

    // reads only one word
    cout<<"The content of the file is "<<content<<endl;

    myFile2.close();

    return 0;
}