#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
 
#define MAX_STR_SIZE 1024
 
int main(int argc, char *argv[])
{
    /* Accept only one alphabetical argument
       which is key for encryption or exit 1 */
    if (argc != 2 || (!isalpha(*argv[1])))
    {
        printf("Missing or incorrect (non-alphabetical) argument: keyword!\n");
        return 1;
    }
     
    int keylen = strlen(argv[1]);
     
    /* Check for digits in string */
    for (int i = 0; i < keylen; i++)
    {
        if (isdigit(argv[1][i]))
        {
            printf("String contains numbers!\n");
            return 1;
        }
    }
     
    char *str = malloc(MAX_STR_SIZE);
    char *key = argv[1];
     
    /* Get plain-text from user */
    fgets(str, MAX_STR_SIZE, stdin);
     
    /* Remove trailing new line character */
    if ((strlen(str) > 0) && (str[strlen(str) - 1] == '\n'))
    {
        str[strlen(str) - 1] = '\0';
    }
     
    /* Get strlen for FOR loop */
    int plainlen = strlen(str);
    int j = 0;
     
    /* Encrypt string */
    for (int i = 0; i < plainlen; i++)
    {
        if (isalpha(str[i]))
        {
            if ((isupper(str[i])))
            {    
                /* Little magic with ASCII math */
                int tmp1 = ((str[i] - 65 + (toupper(key[j])) - 65) % 26) + 65;
                printf("%c", tmp1);
                j = (j + 1) % keylen;
            }
            else if (islower(str[i]))
            {
                /* Little magic with ASCII math */
                int tmp2 = ((str[i] - 97 + (toupper(key[j])) - 65) % 26) + 97;
                printf("%c", tmp2);
                j = (j + 1) % keylen;
            }
        }
        else
        {
            printf("%c", str[i]);
        }
    }
     
    printf("\n");
         
    return 0;
}
