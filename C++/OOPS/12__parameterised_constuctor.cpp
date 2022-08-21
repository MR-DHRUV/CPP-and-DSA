#include <iostream>
#include <math.h>
using namespace std;

class Point
{
    int x, y;
    friend int calcDistance(Point a, Point b);

public:
    Point(int a, int b = 0) // 0 is a default argument
    {
        x = a;
        y = b;
    }
    void getValue(void)
    {
        cout << "The Point is (" << x << "," << y << ")" << endl;
    };
};

int calcDistance(Point a, Point b)
{

    int distance = pow((pow(((a.x) - (b.x)), 2) + pow(((a.y) - (b.y)), 2)), 0.5);
    return distance;
};

int main()
{
    Point P(1, 3);
    Point Q(1);

    P.getValue();
    Q.getValue();

    int dis = calcDistance(P,Q);

    cout<<"The distance is "<<dis<<endl;

    return 0;
}