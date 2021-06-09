// the roots are
// 0.411636
// 1.40642
// 5.18194
//
//
#include <iostream>
#include <cmath>
using namespace std;

double l =0;
double u =0;
double i =0;
double j =0;
double k =0;

double func(double x)
    {
    return pow(x,3)-7*pow(x,2)+10*x-3;
    }

    double sec()
{
    if (func(l) * func(u) < 0) {
        do {
            // calculate the intermediate value
            j = (l * func(u) - u * func(l)) / (func(u) - func(l)); //part of algorithm for Secant method
            // check if j is root of equation or not
            k = func(l) * func(j);
            // update the value of interval
            l = u;
            u = j;
            // if j is the root of equation then break the loop
            if (k == 0)
                break;
            i = (l * func(u) - u * func(l)) / (func(u) - func(l)); //part of algorithm for Secant method
        } while (fabs(i - j) >= .000001/2); //The condition in the while loop defines how accurate and precise the root needs to be
        cout << "Root of the given equation=" << j << endl; //prints root
    } else
        cout << "Can not find a root in the given inteval"; //says if input invalid
}

int main()
{
    int n = 0;
    while (n < 6)
    {
        cout << "Try (0,1), (1,2), (2,5)" << endl;
        cout << "chose starting point" << endl;
        cin >> l;
        cout << "chose ending point" << endl;
        cin >> u;
        sec();
        cout << endl;
        n++;
    }
    return 0;
}