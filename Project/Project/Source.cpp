#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <conio.h>
#include <math.h>

using namespace std;

class Circle
{
    double r;
    int x;
    int y;
public:
    Circle() : r(0), x(0), y(0) {}
    Circle(double r, int x, int y) : r(r), x(x), y(y) {}
    void set_r(double r)
    {
        this->r = r;
    }
    void set_x(int x)
    {
        this->x = x;
    }
    void set_y(int y)
    {
        this->y = y;
    }
    double get_r()
    {
        return r;
    }
    int get_x()
    {
        return x;
    }
    int get_y()
    {
        return y;
    }
    double Area()
    {
        return 2 * 3.14 * r * r;
    }
    double Distance_centre(int x, int y)
    {
        double d;
        if (this->x == x)
            d = abs(this->y - y);
        else if (this->y == y)
            d = abs(this->x - x);
        else
            d = sqrt(pow(abs(this->x - x), 2) + pow(abs(this->y - y), 2));
        return d;
    }
    bool Touch(int x, int y, double r)
    {
        int sum = this->r + r;
        if (Distance_centre(x, y) <= sum)
            return true;
        else
            return false;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Circle c1(2.5, 2, 4);
    Circle c2;
    c2.set_r(3.5);
    c2.set_x(5);
    c2.set_y(2);

    cout << c1.Area() << endl;
    cout << c2.Area() << endl;

    cout << c1.Distance_centre(c2.get_x(), c2.get_y()) << endl;

    cout << c1.Touch(c2.get_x(), c2.get_y(), c2.get_r()) << endl;

    system("pause");
    return 0;
}