#include "nutils.h"
#include <iostream>
#include <cmath>

// Class to represent the user-given function
class Function
{
public:
    // Constructor to initialize the function
    Function(double (*func)(double)) : f(func) {}
    
    // Method to evaluate the function at a given point x
    double evaluate(double x)
    {
        return f(x);
    }
    
    // Method to calculate the Riemann integral of the function on a given interval
    double riemann(double a, double b, int n)
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

private:
    // Pointer to the user-given function
    double (*f)(double);
};

double fx(double x)
{
  return pow(x, 2);
}

// Main function
int main()
{
    // Variables for the lower and upper bounds of the interval
    double a, b;
    
    // Variable for the number of subintervals to use in the calculation
    int n;
    
    // Prompt the user for the interval bounds and number of subintervals
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
