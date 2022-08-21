#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myfile;

    myfile.open("18_sample.txt");

    // writes this is me to the given file;
    myfile << "This is me" << endl;
    myfile << "This is me" << endl;
    myfile << "This is me" << endl;
    myfile << "This is me" << endl;

    cout << "Data saved to file" << endl;

    myfile.close();

    ifstream myFile2;
    myFile2.open("18_sample.txt");

    string data;

    // only one word is taken
    // myFile2>>data;
    // cout<<data<<endl;

    // to read complete file line by line
    // jab tak end of file khaali nahi aata
    while (myFile2.eof() == 0)
    {
        getline(myFile2, data);
        cout << data << endl;
    };

    myFile2.close();

    return 0;
}