#include "nutils.h"
#include <iostream>
#include <cmath>

Function::Function(double (*func)(double)) : f(func) {}
    
double Function::riemann(double a, double b, int n)
{
    // Variable for the width of each subinterval
    double h = (b - a) / n;
    
    // Variable for the sum of the areas of the subintervals
    double sum = 0;
    
    // Loop over the subintervals
    for (int i = 0; i < n; i++)
    {
        // Calculate the left and right bounds of the subinterval
        double left = a + i * h;
        double right = left + h;
        
        // Calculate the height of the subinterval by evaluating the function
        // at the midpoint of the subinterval
        double height = f((left + right) / 2);
        
        // Add the area of the subinterval to the sum
        sum += height * h;
    }
    
    // Return the calculated value of the Riemann integral
    return sum;
}
