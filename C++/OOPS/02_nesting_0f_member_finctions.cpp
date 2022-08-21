#include <iostream>
#include <string>
using namespace std;

class binary
{
public:
    void read(void);
    void ones(void);
    void print(void);

private:
    void chk_bin(void);
    string str;
};

void binary ::read()
{
    cout << "Enter a binary number" << endl;
    cin >> str;
}

void binary ::chk_bin()
{

    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] != '0' && str[i] != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary :: ones()
{   
    chk_bin(); // nesting of function
    for(int k = 0; k < str.length() ; k++){
        if(str.at(k) == '0'){
            str.at(k) = '1';
        }
        else if(str.at(k) == '1'){
            str.at(k) = '0';
        }
    }
}

void binary :: print(){
    cout<<str<<endl;
} 

int main()
{
    binary b;
    b.read();
    // b.chk_bin();
    // b.print();
    b.ones();
    b.print();

    return 0;
}