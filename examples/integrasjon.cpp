#include <iostream>
#include <cmath>

using namespace std;

// Function prototypes
double f(double x);
double riemann(double a, double b, int n);

int main()
{
    // Variables for the lower and upper bounds of the interval
    double a, b;
    
    // Variable for the number of subintervals to use in the calculation
    int n;
    
    // Prompt the user for the interval bounds and number of subintervals
    cout << "Enter the lower bound of the interval: ";
    cin >> a;
    cout << "Enter the upper bound of the interval: ";
    cin >> b;
    cout << "Enter the number of subintervals to use: ";
    cin >> n;
    
    // Calculate and print the Riemann integral
    cout << "The Riemann integral of f(x) on the interval [" << a << ", " << b << "] is: " << riemann(a, b, n) << endl;
    
    return 0;
}

// Function to evaluate the user-given function at a given point x
double f(double x)
{
    // Replace this function with the desired user-given function
    return 3*pow(x, 2);
}

// Function to calculate the Riemann integral of a function on a given interval
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
