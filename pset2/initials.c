1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
/* 
 * File:   initials.c
 * Author: dabaran
 *
 * Created on March 15, 2015, 12:40 PM
 */
 
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
 
#define IN_STR_MAX_SIZE 25
#define OUT_ARR_MAX_SIZE 5
 
int main(int argc, char** argv) {
     
    char input_string[IN_STR_MAX_SIZE];
    char init_array[OUT_ARR_MAX_SIZE];
     
    int init_array_pos;
    bool was_space_before;
     
    init_array_pos = 0;
     
    gets(input_string);
     
    input_string[(strlen(input_string) + 1)] = '\0';
     
    if (isalpha(input_string[0]))
    {
        init_array[init_array_pos] = toupper(input_string[0]);
        was_space_before = false;
        init_array_pos++;
    } else
    {
        was_space_before = true;
    }
     
    for (int i = 1; i <= strlen(input_string); i++)
    {
        if (was_space_before && isalpha(input_string[i]))
        {
            init_array[init_array_pos] = toupper(input_string[i]);
            was_space_before = false;
            init_array_pos++;
        }
         
        if (isspace(input_string[i]))
        {
            was_space_before = true;
        }
    }
     
    init_array[init_array_pos] = '\0';
     
    printf("%s\n", init_array);
     
    return (EXIT_SUCCESS);
}
