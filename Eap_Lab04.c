/* Coding Problems (25 points) */

/*

    Please write code for the two problems below.  Write the code for both
    problems in functions below the main function and call both from the main
    function.  The functions should accept data from main, calculate and return
    the result to main (Problem 2 should print the results for the substance to
    screen.  See below.).  Getting data from the user and printing the results
    should be done in main.  When completed, the main function should get input
    data from the user, call the functions, receive the results of the function
    calls, and print their results to screen.


    1. Write a function that determines the day number (1 to 366) in a year for a
    date that is provided as input data. As an example, January 1, 1994, is day 1.
    December 31, 1993, is day 365. December 31, 1996, is day 366, since 1996 is
    a leap year. A year is a leap year if it is divisible by four, except that any year
    divisible by 100 is a leap year only if it is divisible by 400. Your function should
    accept the month, day, and year as integers from main as arguments. Include an
    additional function leap that returns 1 if called with a leap year, 0 otherwise.
    Sample screen output:

        CALCULATE DAY OF YEAR
        Enter a date: 12 31 2004
        12/31/2004 is the 366th day of 2004

    Note that a leap year is a year that is divisible by 4 but not by 100 or divisible
    by 400.  1900 was not a leap year because it's divisible by 4 but is also divisible
    by 100.  2000 was a leap year because it's divisible by 400.  1904 was a leap year
    because it's divisible by 4 but not divisible by 100.

    2. The table below shows the normal boiling points of several substances. Write
    a function that accepts an argument the observed boiling point of a substance
    in degrees Celsius and identifies the substance if the observed boiling point
    is within 5% of the expected boiling point. If the data input is more than 5%
    higher or lower than any of the boiling points in the table, the function should
    output the message Substance unknown.  Note that the function should print the
    substance and not main.  This will simplify the function call in main.  You need
    to test each substance in an else if chain for the temperature passed from main.

        Substance   Normal boiling point (Celsius)
        Water       100
        Mercury     357
        Copper      1187
        Silver      2193
        Gold        2660

    Your function should define and call a function within_x_percent that takes
    as parameters a reference value ref , a data value data , and a percentage value
    x and returns 1 meaning true if data is within x % of ref -that is, (ref - x%
    * ref) <= data <= (ref + x % * ref) . Otherwise within_x_percent would
    return zero, meaning false. For example, the call within_x_percent(357,
    323, 10) would return true, since 10% of 357 is 35.7, and 323 falls between
    321.3 and 392.7. Sample screen output:

        FIND SUBSTANCE FOR BOILING POINT
        Enter a temperature: 360
        The substance is Mercury

*/


// Preprocessor directives

#include <stdio.h>

#define WATER 100
#define MERCURY 357
#define COPPER 1187
#define SILVER 2193
#define GOLD 2660


// Function prototypes
int leap_year_calc( int year);
int day_calc(int month, day);
int days_calc_with_leaps(int month,day,year);
void print_leap(int year);

double within_x_percent(double ref, double data, double x);

void substance_calc(double ref, double data, double x);


// Main function

int main(){

    int month=0, day=0, year=0, day_count=0;
    printf("This is a calculator for the number of day within a year.\n");
    printf("Enter the month in number form:");
    scanf("%d", &month);
    printf("Enter the day in number form:");
    scanf("%d", &day);
    printf("Enter the year in number form:");
    scanf("%d", &year);

    day_count = days_calc_with_leaps(month, day, year);
    print_leap(year);
    printf("The date of %d/%d/%d is the %dth day of %d.\n\n", month, day, year, day_count, year);

    
    
    double ref =0, data=0, x=0.05;

    printf("This is to determine a substance based on boiling points.\n");
    printf("Enter the boiling point in degrees Celsius: ");
    scanf("%lf", &data);
    
    substance_calc(ref,data,x);

    return 0;
}

// Function for Coding Problem 1
// leap function
int leap_year_calc(int year){
    if((year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0))
        return 1;
    else
        return 0;

 }

int day_calc(int month, day){
    switch(month){ //calc without leap year
        case 1: //jan
            return day;
            break;
        case 2://feb
            return day+31;
            break;
        case 3: //march
            return day+31+28;
            break;
        case 4: //april
            return day+31+28+31;
            break;
        case 5: //may
            return day+31+28+31+30;
            break;
        case 6: //june
            return day+31+28+31+30+31;
            break;
        case 7: //july
            return day+31+28+31+30+31+30;
            break;
        case 8: //aug
            return day+31+28+31+30+31+30+31;
            break;
        case 9: //sept
            return day+31+28+31+30+31+30+31+31;//both july and aug have 31
            break;
        case 10: //oct
            return day+31+28+31+30+31+30+31+31+30;
            break;
        case 11: //nov
            return day+31+28+31+30+31+30+31+31+30+31;
            break;
        case 12:
            return day+31+28+31+30+31+30+31+31+30+31+30;
            break;
        default:
            return 0;
            break;
    }

}

int days_calc_with_leaps(int month,day,year){
    if(leap_year_calc(year)==1)
    {
        return day_calc(month,day) +1;
   }
    else{
        return day_calc(month,day);
    }
}

void print_leap(int year){
    if(leap_year_calc(year)==1)
        printf("It is a leap year!\n");
    return;
}



// Function for Coding Problem 2
// within_x_percent function

double within_x_percent(double ref, double data, double x){
    return(ref-(x*ref)<=data && data<=ref+(x*ref)); // returns either 1 or 0
}



void substance_calc(double ref, double data, double x){
    if(within_x_percent(WATER, data, x)==1)
    printf("The substance is water.\n");
    else if(within_x_percent(MERCURY, data, x)==1)
    printf("The substance is mercury.\n");
    else if(within_x_percent(COPPER, data, x)==1)
    printf("The substance is copper.\n");
    else if(within_x_percent(SILVER, data, x)==1)
    printf("The substance is silver.\n");
    else if(within_x_percent(GOLD, data, x)==1)
    printf("The substance is gold.\n");
    else
    printf("The substance is unknown with the given boiling point %.1f.\n", data);
    return;
}
