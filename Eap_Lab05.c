/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in functions below the main function and call both from the main
    function.  The functions should accept data from main, calculate and return
    the result to main.  Getting data from the user and printing the results
    should be done in main.  When completed, the main function should get input
    data from the user, call the functions, receive the results of the function
    calls, and print their results to screen.



    1. An integer n is divisible by 9 if the sum of its digits is divisible by 9.
    Develop a function to display each digit, starting with the rightmost digit.
    Your program should also determine whether or not the number is divisible by
    9. Write a function that calculates the sum of the digits in an int, checks to
    see if the sum is evenly divisible by 9 and returns 1 for yes and 0 for no.
    Test it on the following numbers:

        n = 154368
        n = 621594
        n = 123456

    Hint: Use the % and 10 operator to get the least significant digit and use /
    and 10 to remove the least significant digit.  Sample output:

    Run 1:
        IS IT DIVISIBLE BY 9
        Enter an integer: 154368
        154368 is divisible by 9

    Run 2:
        IS IT DIVISIBLE BY 9
        Enter an integer: 123456
        123456 is NOT divisible by 9



    2. The value for PI can be determined by the series equation:

        PI = 4(1/1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 ...)

    Write a function using a loop to approximate the value of PI using the formula
    given including terms up through 1/99, 1/999 and 1/9999.  As the number of
    iterations increase, the estimate gets closer to the value of PI. The function
    should accept the number of iterations and return the estimate of PI.

    Hint: To flip the sign from + to -, declare a variable and multiply it by -1
    inside the loop.  Sample output:

    Run 1:
        ESTIMATE PI
        Enter number of iterations: 99
        Estimated PI is 3.121595

    Run 2:
        ESTIMATE PI
        Enter number of iterations: 9999
        Estimated PI is 3.141393



*/

// Preprocessor directives
#include <stdio.h>


// Function prototypes
int calc_sum(int n);
double approximate_pi(int iterations);


// Main function
int main(){

    int entry = 0;

    printf("This is a calculator to find if a number is divisible by 9.\n");
    printf("Enter an integer to calculate: ");
    scanf("%d", &entry);
    calc_sum(entry);




    int iterations = 0;
    printf("This is a calculator to approximate the value for PI.\n");
    printf("Enter the number of iterations to test: ");
    scanf("%d", &iterations);

    approximate_pi(iterations);


    return 0;
}

// Function for Coding Problem 1
int calc_sum(int entry){

    int sum = 0;
    int digit_holder=0;
    int n = entry;

    while(n>0){//will work until no more numbers
        digit_holder = n%10;// find last digit
        printf("%d\n", digit_holder);
        sum += digit_holder;
        n /= 10;
    }
    printf("the sum of %d's individual digits is %d\n", entry, sum);
    if(sum%9==0)
        printf("The sum of %d is divisble by 9, therefore %d is divisible by 9.\n\n",sum, entry);
    else
        printf("The sum of is %d not divisble by 9,therefore %d is not divisible by 9.\n\n",sum, entry);
    return 0;
}


// Function for Coding Problem 2
double approximate_pi(int iterations){
    double odd = 2.0; // increment by 2 to get odds
    double sum_of_fractions = 0.0;
    double sign_change = 1.0; // variable holder to change signs
    for(int i = 1; i<=iterations; i+= odd){
        sum_of_fractions += (sign_change/i);
        sign_change *= -1;
    }
    double approximation = 4 * (sum_of_fractions);
    printf("After %d iterations, the estimated value for PI is: %f\n", iterations, approximation);
    return 0;
}




