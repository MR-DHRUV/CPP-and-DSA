#include<iostream>
#include<vector>

using namespace std;


template <class T>
void display(vector<T> &v)
{

    for (int i = 0; i < v.size(); i++)
    {   
        // same thing 
        // cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
    cout<<endl;
}


int main()
{
    // integer vector of size 4
    // default value will given 0 to all elements
    vector<int> vec2(4);

    // default value : emply line
    vector<char>vec3(4);

    vector<char>vec4(vec3); // 4 element character vector from vec3

    // 6 baar 13 aayga isme
    vector<int> vec5(6,13);

    display(vec5);

    return 0;
}