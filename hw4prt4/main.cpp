//part 4. .88 and 3.786 are the max and min on the gragh, meaning they have a derivative at zero there
//this means that the Newton-R ethod will fail at thos point becaue the derivative wil never hit the x axis.



#include <iostream>
#include <cmath>
using namespace std;

//prototyping 3 function
double func(double l); //this c++ function holds the mathematical function we are finding roots of
double derivfunc(double l); //this c++ function holds the derivative of the mathematical function we are finding roots of
double NR(); //this function executes the Newton-R method
double l=0; //declaring start point variable

//The main funciton calls the other functions in teh correct order
int main()
{
    int n = 0; //this counter prevents an infinite loop
    while (n < 10) //runs through program 9 times
    {
        cout << "Try 0, 1.25, 5" << endl; //asks user for input, prompts good choices
        cout << "chose starting point" << endl;
        cin >> l; //starting point
        cout << endl;
        NR(); //executes the newton-R method
        cout << endl;
        n++; //adds 1 to the counter
    }
    return 0;
}


//this c++ function holds the the mathematical function we are finding roots of
double func(double l)
{
    return pow(l,2)-1;
    //return pow(l,3)-7*pow(l,2)+10*l-3;
}

//this c++ function holds the derivative of the mathematical function we are finding roots of
double derivfunc(double l)
{
    return 2*l;
    //return 3*pow(l,2)-14*pow(l,1)+10;
}

//this function executes the Newton-R method
double NR()
{
    double h = func(l) / derivfunc(l); //function divided by derivative
    while (abs(h) >= .00001/2) //The condition in the while loop defines how accurate and precise the root needs to be
    {
        h = func(l) / derivfunc(l); //part of algorithm for Newton-R method
        //(l+1) = l - func(l) / derivfunc(l) //(want to revisit this later.
        l = l - h; //part of algorithm for Newton-R method
    }
    cout << "The value of the root is : " << l;
    return 0;
}
