/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in the area below designated inside of the main function. When
    completed, the main function should run the code for both problems.

    1. Write code that calculates mileage reimbursement for a salesperson at
    a rate of $.48 per mile. Your program should get the mileage from the user
    in this manner:
        MILEAGE REIMBURSEMENT CALCULATOR
        Enter beginning odometer reading: 13505.2
        Enter ending odometer reading: 13810.6
        You traveled 305.4 miles. At $0.48 per mile, your reimbursement is $146.59.

    2. Write code to convert a temperature in degrees Fahrenheit to degrees
    Celsius. Your program should get the temperature Fahrenheit from the user and
    print the result as:
        FAHRENHEIT TO CELSIUS CALCULATOR
        Enter temperature Fahrenheit: 100.0
        100.0 degrees Fahrenheit is 37.78 degrees Celsius

*/

// Preprocessor directives
#include <stdio.h>
// Main function
int main(){

    double begin_meter=0, end_meter=0, mileage=0, reimbursement=0;


    // Coding Problem 1
    printf("This is a reimbursement calculator for mileage. The rate is $.48 per mile. \n");
    printf("Please enter the beginning odometer reading: ");
    scanf("%lf", &begin_meter);
    printf("Please enter the ending odometer reading: ");
    scanf("%lf", &end_meter);
    mileage = end_meter - begin_meter;
    reimbursement = mileage *0.48;
    printf("You traveled %.2f miles. At $0.48 per mile, your reimbursement is %.2f. \n", mileage, reimbursement);


    // Coding Problem 2

    double fahrenheit=0, celsius=0;

    printf("This is also a temperature conversion calculator. \n");
    printf("Please enter the temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    celsius = (fahrenheit-32) *5 /9;
    printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", fahrenheit, celsius);

// End main function
    return 0;
}
