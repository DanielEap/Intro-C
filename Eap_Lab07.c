/*

Please complete the following problems for Chapter 7.  Please call all three
functions from one main function below.  When completed, the output should
look like:

Problem 1:
locations:
           5   -4    3
           4    3   -2
          -4   -3   -1
          -9    8    6

masses:
           2
           5
           2
           1

number of data points:
n = 4

center of mass:
(1.3, 0.9, 0.0)

Problem 2:
0 1 2 3 4 5 6 7 8 9
6 was found at index 6

Problem 3:
9 8 7 6 5 4 3 2 1 0
0 1 2 3 4 5 6 7 8 9

*/

// Import standard input/output library

#include <stdio.h>

// Function prototypes go here

double center_grav(int matrix[][3], double vector[], int n);
void print_array(int array[], int length);
int binary_search(int array[], int length, int find);
void bubble_sort(int array[], int length);


// Main function goes here

int main(){


    int matrix[10][3];
    double vector[10];
    int n = 0;

    printf("Enter the number of points (maximum 10), n: ");
    scanf("%d", &n);


    center_grav(matrix, vector, n);

    int vector2[] = {0,1,2,3,4,5,6,7,8,9};
    print_array(vector2, 10);
    int found = binary_search(vector2, 10, 4);
    if(found >-1)
        printf("%d was found at index %d\n", vector2[found], found);
    else
        printf("Value not found \n");

    int vector3[] = {9,8,7,6,5,4,3,2,1,0};
    print_array(vector3,10);
    bubble_sort(vector3,10);
    print_array(vector3,10);
    return 0;
}

/*
Problem 1:

A point mass consists of a 3-D location and an associated mass, such as

    Location: (6, 0, -2) Mass: 3g

In a system of point masses, let p1, p2, ..., pn be the n 3-D points and m1,
m2, ..., mn be their associated masses. If m is the sum of the masses, the center
of gravity C is calculated as

    C = 1/m x (m1 x p1 + m2 x p2 + ... + mn x pn)

Write a program that calculates a center of gravity system data from a matrix (points)
and a vector (masses). Display the location matrix, the mass vector, n, and the center
of gravity.  The data set includes a location matrix (a matrix in which each row is a
point), a one-dimensional array of masses, and the number of point masses, n .

Number of data points:
n = 4

Sample point data matrix
5 -4 3
4 3 -2
-4 -3 -1
-9 8 6

Sample mass data vector
2
5
2
1

The sample output should be:

locations:
    5 -4 3
    4 3 -2
    -4 -3 -1
    -9 8 6
masses:
    2
    5
    2
    1
number of data points:
n = 4
center of mass:
(1.3, 0.9, 0.0)

Implement the following function:

center_grav : Takes a location matrix, mass vector, and n value as parameters,
and calculates and returns as the function value the center of gravity
of the system (as an output parameter). The main function should call the
center_grav function, passing necessary arguments. For the point-mass system
data set, display the location matrix, the mass vector, n, and the center of gravity.

*/

// center_grav function goes here


double center_grav(int matrix[][3], double vector[], int n){
    for(int i=0; i<n; i++){
            printf("Enter x coord of point %d: ", i+1);
            int x =0;
            scanf("%d", &x);
            matrix[i][0] = x;

            printf("Enter y coord of point %d: ", i+1);
            int y =0;
            scanf("%d", &y);
            matrix[i][1] = y;

            printf("Enter z coord of point %d: ", i+1);
            int z =0;
            scanf("%d", &z);
            matrix[i][2] = z;

    }
    for(int i=0; i<n; i++){
        double mass = 0.0;
        printf("Enter mass for point %d: ", i+1);
        scanf("%lf", &mass);
        vector[i] = mass;
    }
    double x_total = 0.0, y_total = 0.0, z_total =0.0, mass_total = 0.0;
    for(int i=0; i<n; i++){
        x_total += matrix[i][0] * vector[i];
        y_total += matrix[i][1] * vector[i];
        z_total += matrix[i][2] * vector[i];
        mass_total += vector[i];
    }
    printf("\nlocations: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");}

    printf("masses: \n");
    for(int i=0; i<n; i++)
        printf("%.2f\n", vector[i]);

    printf("Number of data points \nn = %d\n", n);

    printf("Center of mass:\n(%.2f, %.2f, %.2f)\n", x_total/mass_total , y_total/mass_total, z_total/mass_total);

    return 0;
}




/*
Problem 2:

The binary search algorithm that follows may be used to search an array
when the elements are in order. This algorithm is analogous to the following
approach for finding a name in a telephone book.

    a. Open the book in the middle, and look at the middle name on the page.
    b. If the middle name isn't the one you're looking for, decide whether it
        comes before or after the name you want.
    c. Take the appropriate half of the section of the book you were looking in
        and repeat these steps until you land on the name.

ALGORITHM FOR BINARY SEARCH
1. Let bottom be the subscript of the initial array element.
2. Let top be the subscript of the last array element.
3. Let found be false.
4. Repeat as long as bottom isn't greater than top and the target has not been found
    5. Let middle be the subscript of the element halfway between bottom and top.
    6. if the element at middle is the target
        7. Set found to true and index to middle.
    else if the element at middle is larger than the target
        8. Let top be middle - 1.
    else
        9. Let bottom be middle + 1.

Write a function print_array that accepts a vector and the length of the vector that
prints an array on one line as:
9 8 7 6 5 4 3 2 1 0

Write and test a function binary_srch that implements this algorithm for an
array of integers.  Make sure to call binary_srch from your main function.

When there is a large number of array elements, Why is this faster than a
linear search?

*/

// print_array function goes here
void print_array(int array[], int length){
    for(int i=0; i<length; i++)
        printf("%d ", array[i]);
    printf("\n");

}

// binary_srch function goes here

int binary_search(int array[], int length, int find){
    int bottom = 0;
    int top = length-1; // last element
    int middle = (top + bottom)/2;

    while(bottom <= top){

        if(find < array[middle]){
            top = middle - 1;

        }
        else if(find > array[middle]){
            bottom = middle + 1;

        }
        else
            return middle;
        middle = (top + bottom)/2;
    }
    return -1;
}

/*

The bubble sort is another technique for sorting an array. A bubble sort compares
adjacent array elements and exchanges their values if they are out of
order. In this way, the smaller values "bubble" to the top of the array (toward
element 0), while the larger values sink to the bottom of the array. After the
first pass of a bubble sort, the last array element is in the correct position; after
the second pass the last two elements are correct, and so on. Thus, after each
pass, the unsorted portion of the array contains one less element.

Write a function print_array to print an array on one line as:
9 8 7 6 5 4 3 2 1 0

Write and test a function called bubble_sort that implements this sorting method and
call it from your main function.  You will need to swap elements to sort the array.

*/

// bubble_sort function goes here

void bubble_sort(int array[], int length){
    for(int i=0; i < length-1; i++){
        for(int j = length-1; j>0; j--)
            if(array[j] < array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
    }
}
