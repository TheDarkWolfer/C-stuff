#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//TODO : Implement the possibility of computing for x digits of pi instead of x iterations
//TODO : (that's probably gonna require a total rewrite of the variables and their handling...)

int parseInteger(char *arg) {
    char *endptr;
    long value;

    // Attempt conversion of the provided data into a long integer
    value = strtol(arg, &endptr, 10);

    //fprintf(stdout,"VALUE' : %li\nARGUMENTS : %s",value,arg);//For debug purposes

    // If the end pointer is a null byte it means nothing was inputted,
    // if the end pointer is the provided argument, something was inputted wrong
    // if the value is greater or smaller than the maximum or minimum value for an integer,
    // there was an issue there too.
    // In any cases, we log to the user and return a negative number.
    if ((*endptr !='\0' || endptr == arg) || (value < INT_MIN || value > INT_MAX)) {
        fprintf(stderr, "Error with integer input. Please try again.\n");
        return -1;
    }

    return value;
}

long double computePi(int precisionPoint) {

    //? implementation of the Chudnovsky Algorithm
    //? https://en.wikipedia.org/wiki/Chudnovsky_algorithm

    long double C = 640320;
    long double C3_over_24 = pow(C, 3) / 24.0;

    long double K = 6;          // factorial multiplicator for numerator
    long double M = 1;          // initial term of the series
    long double X = 1;          // denominator component
    long double L = 13591409;   // linear term in the series
    long double S = L;          // sum of the series starts with first term

    // Iterating for the desired precision
    for (int iteration; iteration < precisionPoint; iteration++) {
        // Update numerator component M
        M = M * (K * ( K - 1) * (K - 2) ) / pow(K, 3);

        // Update linear term L
        L = L + 545140134;

        // Update denominator term X
        X = X * (-C3_over_24);

        // Add current term S to the sum 
        S = S + (M * L) / X;

        // Update factorial multiplicator K for the next iteration
        K += 12;
    }

    // Last computation of Pi
    long double pi = (426880 * sqrt(10005)) / S;
    return pi;
}

int main(int argc, char *argv[]) {

    //! DISCLAIMER : THIS IS MY FIFTH EVER PROGRAM WRITTEN IN C. 
    //! DON'T EXPECT IT TO BE WELL-WRITTEN OR EFFICIENT, EXPECT IT TO WORK.
    //example output 3.14159265358973394609808094113390097845694981515407562255859375

    // If there are more or less than two arguments, there was an issue somewhere.
    if (argc != 2) {
        fprintf(stderr,"Only one argument expected : the precision of the digits of Pi we process\n");
        fprintf(stdout, "NOTE : Precision =/= amount of digits after the decimal, it is just \nthe amount of iteration the algorithm will go through when computing Pi\n");
        return 1;
    }

    // Take in the argument as the desired precision of the digits of Pi
    int precision = parseInteger(argv[1]);

    // If the precision is lower than 0, it either means the user inputted something wrong,
    // as the parseInteger function returns -1 in cases of error, or that the user gave a 
    // negative mumber, which we can't really parse.
    if (precision < 0) {
        fprintf(stderr, "Precision asked is not a positive integer, please retry\n");
        return 1;
    }

    //Now onto computing Pi
    long double pi = computePi(precision);

    char buffer[128];

    snprintf(buffer, sizeof(buffer), "%.*Lf", precision, pi);

    int len = strlen(buffer);
    int end = len - 1;

    // Trim trailing zeros after the decimal point
    while (end > 0 && buffer[end] == '0') {
        end--;
    }
    // Remove any period there may be in the end
    if (buffer[end] == '.') {
        end--;
    }

    // Add null terminator if we removed it by accident
    buffer[end + 1] = '\0';
    
    // Display the result to the user
    fprintf(stdout, "Computed pi to %d digits of precision:\n> %s <\n", precision, buffer);
    
    //// Bruh if my shitty code gets us there it's party time
    return 0;
}