/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in functions below the main function and call both from the main
    function.  The functions should accept data from main, calculate and return
    the result to main.  Getting data from the user and printing the results
    should be done in main.  When completed, the main function should get input
    data from the user, call the functions, receive the results of the function
    calls, and print their results to screen.

    1. You have saved $500 to use as a down payment on a car. Before beginning
    your car shopping, you decide to write a function to help you figure out what
    your monthly payment will be, given the car's purchase price, the monthly
    interest rate, and the time period over which you will pay back the loan. The
    formula for calculating your payment is:

        payment =    iP
                    ________________
                    1 - (1 + i)^(-n)
        where
        P = principal (the amount you borrow)
        i = monthly interest rate ( 1/12 of the annual rate)
        n = total number of payments

    Your program should get input data from the user in the main function in this manner:
        CALCULATE PAYMENT
        Enter principal: 500.0
        Enter annual interest rate: 6.0
        Enter number of payments: 24
        Your monthly payment is: 22.16


    2. For any integer n > 0, n! is defined as the product n * (n - 1) * (n - 2) … * 2 * 1.
    0! is defined to be 1. It is sometimes useful to have a closed-form definition instead;
    for this purpose, an approximation can be used. R.W. Gosper proposed the following
    such approximation formula:

        n! = n^n x e^(-n) x square_root((2n + 1/3) x pi)

    Create a function that prompts the user to enter an integer n , uses Gosper's
    formula to approximate n!, and then displays the result. The input data should
    be read and output result should be printed in the main function, and the calculation
    should be in the function for Problem 2. The message displaying the result should look
    something like this:

        Enter a number: 5
        5! equals approximately 119.97003

    Your program will be easier to debug if you use some intermediate values
    instead of trying to compute the result in a single expression. If you are not
    getting the correct results, then you can compare the results of your intermediate
    values to what you get when you do the calculations by hand. Use at least two
    intermediate variables - one for 2n + 1/3 and one for (2n + 1/3) x pi.

    Display each of these intermediate values to simplify debugging. Be sure to
    use a named constant for PI, and use the approximation 3.14159265 and use a
    constant for E, approximated as 2.718281827. Test the program on nonnegative
    integers less than 8.

*/


// Preprocessor directives

#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define E 2.718281827


// Function prototypes

double calc_principal(double car_price, double down_payment);
double calc_monthly_rate(double annual_rate);
double calc_denom(double annual_rate, double num_payments);
double calc_periods(double num_payments);
double calc_monthly_payment(double car_price, double down_payment, double annual_rate, double num_payments);

double calc_n_squared(int n_value);
double calc_e_pow_neg_n(int n_value);
double calc_radicand(int n_value);
double calc_square_root(int n_value);


// Main function

int main(){

// Function for Coding Problem 1
   double down_payment=0, car_price=0, annual_rate=0, num_payments=0;

   printf("What is the purchase price of the car? ");
   scanf("%lf", &car_price);

   printf("What is the down payment? ");
   scanf("%lf", &down_payment);

   printf("What is the annual interest rate? ");
   scanf("%lf", &annual_rate);

   printf("How many payments will there be? ");
   scanf("%lf", &num_payments);

   /* double principal = calc_principal( car_price, down_payment );

   double monthly_interest_rate = calc_monthly_rate(annual_rate);

   double rate_plus_one = calc_rate_plus_one(monthly_interest_rate);

   double periods_exponent = calc_periods(num_payments);

   double exponent_part = calc_exponent_part(rate_plus_one, periods_exponent);

   double monthly_payment = calc_monthly_payment(monthly_interest_rate, principal, exponent_part);*/
    double principal = calc_principal( car_price, down_payment);
    double monthly_payment = calc_monthly_payment( car_price,  down_payment,  annual_rate,  num_payments);
   printf("The amount borrowed will be $%.2lf\n", principal);
   printf("The monthly payment will be $%.2lf\n", monthly_payment);

// Function for Coding Problem 2

   int n_value=0;

    printf("\nEnter an non-zero integer value for n to find the factorial, using Gosper's formula ");
    scanf("%d", &n_value);


    double factorial_value = calc_square_root(n_value);


   printf("%d! is approximately equal to %.5lf.", n_value, factorial_value);

   return 0;

}

double calc_principal(double car_price, double down_payment){ // P
    return (car_price - down_payment);
}

double calc_monthly_rate(double annual_rate){ //i
    return (annual_rate/1200);
}
double calc_periods(double num_payments){//-n
    return -(num_payments);
}
double calc_denom(double annual_rate, double num_payments){// (1 + i)^(-n)
    return pow((1+ calc_monthly_rate(annual_rate)), calc_periods(num_payments));
}

double calc_monthly_payment(double car_price, double down_payment, double annual_rate, double num_payments){
    return (calc_monthly_rate(annual_rate) * calc_principal(car_price, down_payment)) / (1.0 - calc_denom(annual_rate,num_payments));
}

double calc_n_squared(int n_value){ //n^n
    return pow(n_value, n_value);
}

double calc_e_pow_neg_n(int n_value){//e^-n
    return pow(E,-n_value);
}
double calc_radicand(int n_value){//(2n + 1/3) x pi)
    return ((1.0/3.0 + (2.0 * n_value)) * PI);
}

double calc_square_root(int n_value){
    return calc_n_squared(n_value) * calc_e_pow_neg_n(n_value) * sqrt(calc_radicand(n_value));
}

