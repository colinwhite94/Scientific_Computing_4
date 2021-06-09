/*
File name: HW 4, use 3 methods to find the roots of 5 equations
Author: Colin White
Date; 29 may 2018
Description: This program read works primarily by calling functions in the right order. The equation function gathers input
 for what equation the user wants to use. The range function gathers what range or starting point the user wants
 to start looking for a root over. The method function asks what method the user wants to use, from the method function
 the user is directed to one of the 3 methods (bisection, newton-r, or secant method. That method loads the proper
 equation to use based on information gathered in the equation function. There are func function holds the 5 equations
 in their raw form for the method function to load up. the derivfunc function holds the derivatives for the newton- R
 method
 */
#include <iostream>
#include <cmath>
using namespace std;

//here I prototype all my function.
double equation (); //This function lets people chose what equation to find roots of.
double range(); //This function lets user enter what range (or starting point) they want to check for roots on.
double method (); //This function lets people chose the method of finding the root they want to use
double bisection(int e); //this calculates roots using bisection method methods
double NR(int e); //this calculates roots using NR method
double sec(int e); //this calculates roots using secant method
double func(int e, double x); //stores equations in raw form
double derivfunc(int e, double x); //stores derivative of equations

//Here i declare various variable that help in calling and using function I declared them uuniversallybecause it worked better.
string s; //stores equation choice as a string
string t; //stores method choice as a string
int e = 0; //stores what equation they want
int m = 0; //stores the method type
double l = 0; //stores lower limit of range, or starting point
double u = 0; //stores upper limit of range, or unused variable
double mid = 0;//stores the midpoint in bisection method
double x = 0;  //independent variable for returning equation function values
double i = 0; //used in secant method
double j = 0; //used in secant method
double k = 0; //used in secant method

//the main function basically calls the other functions in the correct order
int main() {
    equation(); //calling equation function
    range(); //calling range function
    method(); //calling method function
    return 0;
}

//this is the function that asks for the equation to find the root of
double equation()
{
    //explaining the equation options to the user
    cout << "what equation do you want to use?" << endl << "enter 1 for y=x^3-1" << endl << "enter 2 for y=x^2-4" << endl << "enter 3 for y=3^x-5" << endl << "enter 4 for y=ln(x)" << endl << "enter 5 for y=(x-2)^5-2" << endl;
    cin >> e; //gathering the user input
    //these if, if else, and else statements are the flow control for getting the right information outputted
    if(e==1)
        {
        s = "y=x^3-1"; //stores equation as string to print out later
        return 0;
        }
    else if(e==2)
        {
        s = "y=x^3"; //stores equation as string to print out later
        return 0;
        }
    else if(e==3)
        {
        s = "y=3^x-5"; //stores equation as string to print out later
        }
    else if(e==4)
        {
        s = "y=ln(x)"; //stores equation as string to print out later
        }
    else if(e==5)
        {
        s = "y=(x-2)^5-2"; //stores equation as string to print out later
        }
    else
        {
        cout << "I did not understand, restart program";
        }
    cout << endl;
    return 0;
}

//This function gathers and stores the range or starting point the user wants to start looking for roots with.
//It also prompts the correct range or starting points
double range()
{
    //This if/else if/else flow control makes sure that the user is promoted with the right vale for a range based on the equation choice
    if(e==1) //if equation 1 is chosen
        {
        cout << "For bisection method enter a range to look for roots over. A good choice this equation is (-1, 1)" << endl;
        cout << "For N-R method enter lower limit, or starting point (-1)"<< endl;
        cout << "For Secant method enter lower secant point, and higher secant point (-1 and 1)"<< endl;
        cout << "enter the first number followed by enter, then the second number"<< endl;
        cin >> l;
        cout << "enter upper limit"<< endl;
        cin >> u;
        }
    else if(e==2) //if equation 2 is chosen
        {
        cout << "For bisection method enter a range to look for roots over. A good choice for this equation is (-3, -1) or (1, 3)" << endl;
        cout << "For N-R method enter lower limit, or starting point (-3 or 1)" << endl;
        cout << "For Secant method enter lower secant point, and higher secant point (1 and 3)"<< endl;
            cout << "enter the first number followed by enter, then the second number"<< endl;
        cin >> l;
        cout << "enter upper limit or ending point"<< endl;
        cin >> u;
        }
    else if(e==3) //if equation 3 is chosen
        {
        cout << "For bisection method enter a range to look for roots over. A good choice this equation is (0, 2)" << endl;
        cout << "For N-R method enter lower limit, or starting point (1)"<< endl;
        cout << "For Secant method enter lower secant point, and higher secant point (1 and 2)"<< endl;
        cout << "enter the first number followed by enter, then the second number"<< endl;
        cin >> l;
        cout << "enter upper limit"<< endl;
        cin >> u;
        }
    else if(e==4) //if equation 4 is chosen
        {
        cout << "For bisection method enter a range to look for roots over. A good choice this equation is (0, 2)" << endl;
        cout << "For N-R method enter lower limit, or starting point (1)"<< endl;
        cout << "For Secant method enter lower secant point, and higher secant point (.5 and 2)"<< endl;
        cout << "enter the first number followed by enter, then the second number"<< endl;
        cin >> l;
        cout << "enter upper limit"<< endl;
        cin >> u;
        }
    else //if equation 5 is chosen
        {
        cout << "For bisection method enter a range to look for roots over. A good choice this equation is (0, 4)" << endl;
        cout << "For N-R method enter lower limit, or starting point (3)"<< endl;
        cout << "For Secant method enter lower secant point, and higher secant point (3 and 4)" << endl;
        cout << "enter the first number followed by enter, then the second number"<< endl;
        cin >> l;
        cout << "enter upper limit"<< endl;
        cin >> u;
        }
    return 0;
}

//this function asks what method the user wants to find root with.
//It also aggrigates all the information and prints out a statement that explains what the function will do based on user input.
double method ()
    {
    // explaining the equation options to the user
    cout << "What method would you like to use?" << endl << "enter 1 for braketing" << endl << "enter 2 for Newton-R" << endl << "enter 3 for Secant" << endl;
    cin >> m; //input for method choice
    if (m==1) //bisection method
        {
         t = "braketing"; //stores method choice as string
        }
    else if (m==2) //Newton-R method
        {
        t = "Newton-R"; //stores method choice as string
        }
    else if (m==3) //Secant method
        {
        t = "Secant"; //stores method choice as string
        }
    else
        {
        cout << "I did not understand, start program again";
        }
    //Here the program prints out a statement that explains what the function will do based on user input.
    cout << "we will find the roots of"<< "\t" << s << "\t" << "using the" << "\t" << t << "\t" "method between" << "\t" << l << "\t" << "and" << "\t" << u <<endl;

    //this flow controll calls the correct numerical method based on method choice
    if (m==1)
        {
        bisection(e); //calls bisection method
        }
    else if (m==2)
        {
        NR(e); //calls Newton-R method
        }
    else if (m==3)
        {
        sec(e); //calls secant method
        }
    return 0;
   }

// TO AVOID CONFUSION
//for the bisection, Newton_R and Secant method, I ofter call equations from the func() function.
//When calling the equation from function, there are always 2 values that are passed
//"e" is always there, its purpose is to navigate the func() function and grab the right equation (it is gathered in the equation function earlier in the code)
//the second value passed to func() is the value the equation functionding the function value of


//this function is the bisection method. It calls, then used the right equation from the func() function based on user input (e) from the equation function
double bisection(int e)
{
    //some unused code I might want to revisit.
    //if (func(e, l, u=NULL, mid=NULL) * func(e, l=NULL, u, mid=NULL) >= 0)
    // {
    //    cout << "Either lower or upper not correct\n";
    //    return 0;
    // }
    double  mid = l;
    while ((u-l) >= .000001/2) //The condition in the while loop defines how accurate and precise the root needs to be
    {
        // Find middle point
        mid = (l+u)/2;
        // Check if middle point is root
        if (func(e, mid) == 0.0) //the e grabs the correct equation from the func() function, the mid finds the function value at mid
            break;
            // Decide the side to repeat the steps
        else if (func(e, mid) * func(e, l) < 0)
            u = mid;
        else
            l = mid;
    }
    cout << "The value of root is : " << mid; //prints the location of the root.
    return 0;
}

//this function is the Newton-R method. It calls, then used the right equation from the func() function based on user input (e) from the equation function
double NR(int e)
    {
    x=l;
    double h = func(e, x) / derivfunc(e, x); //function divided by derivative
    while (abs(h) >= .00001/2) //The condition in the while loop defines how accurate and precise the root needs to be
    {
        h = func(e, x) / derivfunc(e, x); //part of algorithm for Newton-R method
        // x(i+1) = x(i) - f(x) / f'(x) (want to revisit this later.
        x = x - h; //part of algorithm for Newton-R method
    }
    cout << "The value of the root is : " << x;
    return 0;
    }

//this function is the secant method. It calls, then used the right equation from the func() function based on user input (e) from the equation function
double sec(int e)
{
    if (func(e,l) * func(e, u) < 0) {
        do {
            // calculate the intermediate value
            j = (l * func(e,u) - u * func(e,l)) / (func(e,u) - func(e, l)); //part of algorithm for Secant method
            // check if j is root of equation or not
            k = func(e,l) * func(e, j);
            // update the value of interval
            l = u;
            u = j;
            // if j is the root of equation then break the loop
            if (k == 0)
                break;
            i = (l * func(e,u) - u * func(e,l)) / (func(e,u) - func(e,l)); //part of algorithm for Secant method
        } while (fabs(i - j) >= .000001/2); //The condition in the while loop defines how accurate and precise the root needs to be
        cout << "Root of the given equation=" << j << endl; //prints root
    } else
        cout << "Can not find a root in the given inteval"; //says if input invalid
}

//this is the function the method function calls to get the right equation in its raw form
double func(int e, double x)
{
    if (e==1) //if 1 equation chosen
        {
        return pow(x,3);
        }
    else if (e==2) //if 2 equation chosen
        {
        return pow(x,2)-4;
        }
    else if (e==3) //if 3 equation chosen
        {
        return pow(3,x)-5;
        }
    else if (e==4) //if 4 equation chosen
        {
        return log(x);
        }
    else //if 5 equation chosen
        {
         return pow((x-2),5)-2;
        }
}

//this is the function the method function calls to get the right derivative of the right equation for the Newton-R method.
double derivfunc(int e, double x)
{
    if (e==1) //if 1 equation chosen
        {
        return 3*pow(x,2);
        }
    else if (e==2) //if 2 equation chosen
        {
        return 2*x;
        }
    else if (e==3) //if 3 equation chosen
        {
        return log(3)*pow(3,x);
        }
    else if (e==4) //if 4 equation chosen
        {
        return 1/x;
        }
    else //if 5 equation chosen
        {
        return 5*pow((x-2),4);
        }
}


