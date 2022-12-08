#ifndef NUTILS_H_
#define NUTILS_H_


class Function
{
public:
    /*
     * Constructor to initialize the function
     */
    Function(double (*func)(double));   

    /*
     * Method to calculate the Riemann integral of the function on a given interval
     */
    double riemann(double a, double b, int n);

private:
    /*
     * Pointer to the user-given function
     */
    double (*f)(double);
};

#endif
