//part 3.  The roots are at -0.407658, 2.53123, 3.87643
#include <cmath>
using namespace std;

double l=0;
double u=0;

double func(double x)
{
        return -10-18*x+15*pow(x,2)-2.5*pow(x,3);
}

double bisection()
{
    //some unused code I might want to revisit.
    if (func(l) * func(u) >= 0)
    {
        cout << "Either lower or upper not correct\n";
        return 0;
    }
    double  mid = l;
    while ((u-l) >= .000001/2) //The condition in the while loop defines how accurate and precise the root needs to be
    {
        // Find middle point
        mid = (l+u)/2;
        // Check if middle point is root
        if (func(mid) == 0.0) //the e grabs the correct equation from the func() function, the mid finds the function value at mid
            break;
            // Decide the side to repeat the steps
        else if (func(mid) * func(l) < 0)
            u = mid;
        else
            l = mid;
    }
    cout << "The value of root is : " << mid; //prints the location of the root.
    return 0;
}

int main()
{
    int n = 0;
    while (n < 5)
    {
        cout << "Try (-1,0), (2,3), (3,5)" << endl;
        cout << "chose lower limit" << endl;
        cin >> l;
        cout << "chose upper limit" << endl;
        cin >> u;
        cout << endl;
        bisection();
        cout << endl;
        n++;
    }
    return 0;
}