/*
 * greedy.c
 *
 *  Created on: Sep 13, 2014
 *      Author: Damian Baran
 */
 
#include <cs50.h>
#include <stdio.h>
#include <math.h>
 
int main()
{
    /* Initialize variables */
 
    /* input - is for user input
     * rounded - to round user's input
     * i_rounded - to type cast rounded
     * tp_cast - to type cast result of modulo operation (find highest multiplier)
     * counter - is for for loop
     * val - is for for loop in order to change different values of different coins
     * sum_l - local multiplier
     * sum_g - gloabl multiplier (result of this pset)
     */
 
    float input, rounded;
    int i_rounded, tp_cast, counter, val;
    int sum_l = 0, sum_g = 0;
 
    printf("O hai!  How much change is owed?\n");
    input = GetFloat();
 
    while (input <= 0.0)
    {
        printf("How much change is owed?\n");
        input = GetFloat();
    }
 
 
    rounded = roundf(input*100);            // Round to two decimal places
    i_rounded = (int)rounded;               // Type cast float variable rounded, into int variable i_rounded
 
 
    while(i_rounded != 0)
    {
        for(counter = 0; counter <= 3; counter++)
        {
            if(counter == 0)
            {
                val = 25;
            }
            else if (counter == 1)
            {
                val = 10;
            }
            else if (counter == 2)
            {
                val = 5;
            }
            else if (counter == 3)
            {
                val = 1;
            }
 
            /* If modulo of division by variable val is equal to zero find multiplier and break loop */
            if ((i_rounded % val) == 0)
            {
                sum_g += (i_rounded / val);
                sum_l = (i_rounded / val);
                i_rounded -= (sum_l * val);                 // Should make while loop TRUE
                break;
            }
            else                                            // Else find highest multiplier by type casting result of division
            {
                tp_cast = (int)(i_rounded / val);
                i_rounded -= (tp_cast * val);
                sum_g += tp_cast;
            }
        }
    }
 
    printf("%d\n", sum_g);
 
 
    return 0;
 
}
