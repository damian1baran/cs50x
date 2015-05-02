/*
 * Name:            pset1
 * Description:     First problem set of CS50x course delivered by HarvardX and edx.org
 *
 * Author:          Damian Baran
 * Date:            8th of September 2014
 * Time:            1:46 Local Time (Time Zone: EST or in other words UTC+2)
 */
 
#include <cs50.h>
#include <stdio.h>
 
int main()
{
    int height;
 
    printf("Height: ");
    height = GetInt();
 
    while(1)
    {
 
        if ( (height >= 0) && (height <= 23) )
        {
            break;
        }
 
        else if ( height < 0 )
        {
            printf("Please enter positive number: ");
            height = GetInt();
            continue;
        }
 
        else if ( height > 23)
        {
            printf("Greatest number can be 23: ");
            height = GetInt();
            continue;
        }
 
        else
        {
            printf("Height: ");
            height = GetInt();
        }
 
 
    }
 
    int v, he, hh;
    int empty = height - 1;
    int hash = 2;
 
    /* Print vertical lines */
    for (v = 0; v < height; v++)
    {
 
        for (he = 0; he < empty; he++)
        {
            printf(" ");
        }
 
        for (hh = 0; hh < hash; hh++)
        {
            printf("#");
        }
 
        printf("\n");
 
        empty--;
        hash++;
 
    }
 
 
    return 0;
}
