#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age : ";
    cin >> age;

    switch (age)
    {
    case 1:
        cout << "You are a kiddo lmao can come to the party";
        break;
    case 2:
        cout << "You are a kiddo lmao can come to the party";
        break;
    case 3:
        cout << "You are a kiddo lmao can come to the party";
        break;
    case 15:
        cout << "You cant come to the party";
        break;
    case 18:
        cout << "You can come to the party";
        break;

    default:
        cout << "You cant come to the party";
        break;
    }


    // agar break ni lagaoge toh pass case ke baad ke saare case run ho jayenge aur true ho jayenge automatically 

    return 0;
}