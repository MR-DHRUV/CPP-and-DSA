#include <iostream>
#include <cstring>
using namespace std;

class CWH
{
protected:
    string title;
    double rating;

public:
    CWH(string s, double r)
    {

        title = s;
        rating = r;
    }
    virtual void display()
    {
        cout << "display of base class is called" << endl;
    }
};

class CWHvideo : public CWH
{
    int videolen;

public:
    CWHvideo(string s, double r, int vl) : CWH(s, r), videolen(vl)
    {
        cout << "CWHVideo constructor called" << endl;
    }
    void display()
    {
        cout << "video " << title << endl;
        cout << "videolen " << videolen << endl;
        cout << "rating " << rating << endl;
    };
};

class CWHtext : public CWH
{
    int words;

public:
    CWHtext(string s, double r, int w) : CWH(s, r), words(w)
    {
        cout << "CWHtext constructor called" << endl;
    };
    void display()
    {
        cout << "video " << title << endl;
        cout << "words " << words << endl;
        cout << "rating " << rating << endl;
    }
};

int main()
{
    string title;
    int vl, w;
    double r;

    title = "This is a tutorial to cpp";
    r = 4.6;
    vl = 8;
    w = 9;

    CWHvideo video(title, r, vl);
    // video.display();

    CWHtext text(title, r, w);
    // text.display();

    CWH *ptr[2];

    ptr[0] = &video;
    ptr[1] = &text;

    // no mess up , their own displays are called as display of base class is a virtual function;
    ptr[0]->display();
    ptr[1]->display();

    return 0;
};

// rules for defining virtual functions
// cant be static
// accessed only by object pointers
// can be a friend function
// virtual function in base class might not be used