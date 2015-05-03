#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define MAX_STR_SIZE 1024
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Missing argument: rotation number!\n");
        return 1;
    }
    else
    {
        /* 1. Convert argv[1] to integer and assing it to unsigned int var
           2. Initialize pointer and allocate memory with max size specified */
        unsigned int argument = atoi(argv[1]);
        char *str = malloc(MAX_STR_SIZE);
 
        fgets(str, MAX_STR_SIZE, stdin);
         
        /* Remove trailing new line character */
        if ( (strlen(str) > 0) && (str[strlen(str) - 1] == '\n') )
        {
            str[strlen(str) - 1] = '\0';
        }
         
        /* For loop to encrypt/rotate alphabet characters
           Should skip non-alphabet characters and print them 
           'as is'. Rotation from argument is used for encryption.
            Modular arithmetic used in printf() function */
        for (int i = 0, n = strlen(str); i < n; i++)
        {
            if (isalpha(str[i]))
            {
                if ((isupper(str[i])))
                {    
                    printf("%c", ( (str[i] - 65 + argument ) % 26 ) + 65);
                }
                else if ( islower(str[i]) )
                {
                    printf("%c", ( (str[i] - 97 + argument ) % 26 ) + 97);
                }
            }
            else
            {
                printf("%c", str[i]);
            }
        }
         
        printf("\n");
         
        /* Free memory */
        free(str);
    }
     
    return 0;
}
