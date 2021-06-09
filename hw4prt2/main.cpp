//part 2. the max is ay 5.33583


#include <iostream>
#include <cmath>

using namespace std;


double fun(double x)
{
    return -3*pow(x,6)-4*pow(x,4)+5*x+3;
}

int main()
{
    double a=0, b=1, c = 0;
    int n=0;

    while (fabs(a-b) >= .0000001 && n<=500)
        {
        c = (a+b)/2;
        if (fun(c) < fun(a))
            {
            b=c;
            }
        else
            {
             a=c;
            }

            n++;
        }
        double k=fun(c);

    cout << "the max is " << k << endl;
    cout << "number of iterations " << n << endl;
    cout << "it happens at " << c;

    return 0;
}
