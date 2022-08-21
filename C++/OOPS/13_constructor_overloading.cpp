#include <iostream>
using namespace std;


// one class can have multiple constructors
class Point
{
    int x, y;
    friend int calcDistance(Point a, Point b);

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    };

    Point(int a)
    {
        x = a;
        y = 0;
    };

    void getValue(void)
    {
        cout << "The Point is (" << x << "," << y << ")" << endl;
    };
};


int main()
{
    Point P(2, 3);
    P.getValue();

    Point Q(5);
    Q.getValue();

    return 0;
}