#include "../nutils.h"
#include <iostream>
#include <cmath>

double fx(double x)
{
  return pow(x, 2);
}

int main()
{
    // Variables for the lower and upper bounds of the interval
    double a, b;
    
    // Variable for the number of subintervals
    int n;
    
    std::cout << "Enter the lower bound of the interval: ";
    std::cin >> a;
    std::cout << "Enter the upper bound of the interval: ";
    std::cin >> b;
    std::cout << "Enter the number of subintervals to use: ";
    std::cin >> n;
    
    // Create a Function object to represent the user-given function
    Function func(&fx);
    
    // Calculate and print the Riemann integral
    std::cout << "The Riemann integral of f(x) on the interval [" << a << ", " << b << "] is: " << func.riemann(a, b, n) << std::endl;

    return 0;
}

