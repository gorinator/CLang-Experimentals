/*
Protected int function that returnes only int values in a custom range. 
Allowable int range sets as arguments to function.
Function reply input again before digit will not be on first place in input 
and calulate lenth of digital part, and skipp all other chars after digital part.
*/

#include <iostream>

int askint(int intmin, int intmax); // needed if function code not in top of the other code

int askint(int intmin, int intmax) { // protected input of only int values in a range, int range sets as arguments in function
    int intanswer = -2147483648; // min_int value for initialisation
    do {
        printf("Enter number from %i to %i:", intmin, intmax);
        std::string intin;
        std::cin >> intin;
        int k = 0;
        int n = 0; // digitlen
        int c = 1; // multiplier
        while (intin[k] != 0 && (intin[k] >= '0' && intin[k] <= '9')) { // find digital part lenth and calculate needed multiplier
            if (k > 0) {
                c *= 10;
            }
            n++;
            k++;
        }
        if (n > 0) {
            intanswer = 0;
            for (int i = 0; i < n; i++) {
                int temp = int(intin[i]) - 48; // decode char to int ASCII position and correct to rigt result by bias
                intanswer += temp * c; //multiplier of register depended on digitlen
                c /= 10; //change multiplier for next digit
            }
        }
    } while (intanswer < intmin || intanswer > intmax);
    return intanswer;
}