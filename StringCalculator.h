#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* delimiters = ",\n"; // Delimiters: commas and new lines
char* Default_Delimeters = ";,\n";
int sum = 0;
#define THOUSAND 1000
#define ZERO 0

void throw_negatives_error(char* PrintNegativeNum) {
    printf("Negatives not allowed: %s\n", PrintNegativeNum);
    //exit(1); // You can handle this error in a way that fits your requirements
}
int IsStringEmpty(const char* String_empty)
{
    if (!String_empty || *String_empty == '\0') {
        return 0; // Return 0 for an empty input
    }
}
int NumberIsGreaterThousand(int Number)
{
    int sum = ZERO;
    if (Number >= THOUSAND)
    {
        return ZERO;
    }
    else
    {
       return sum+=Number;
    }
}

int CheckIfNegative(char* String)
{
   const char char_Var = '-';
   char *ret_var;

   ret_var = strrchr(String, char_Var);
    if (ret_var)
    {
        throw_negatives_error(ret_var);
    }

}
char* DelimeterFinal(const char* InputString_DelimeterSelection)
{
    if(strstr(InputString_DelimeterSelection,"//"))
    {
       return Default_Delimeters;        
    }
    else
    {
        return delimiters; 
    }
}


// Function to calculate the sum of numbers in the input string
int add(const char* InputStringNumber) {
    int sum = ZERO;
    char* token;
        char* input_copy = strdup(InputStringNumber); // Make a modifiable 
        char* DelimitersWithString = DelimeterFinal(InputStringNumber);
        token = strtok(input_copy, DelimitersWithString);
        IsStringEmpty(InputStringNumber);
        CheckIfNegative(input_copy);
        // Iterate through all tokens and sum the numbers
    while (token != NULL) {
        sum += NumberIsGreaterThousand(atoi(token));
        token = strtok(NULL, DelimitersWithString);
    }
    return sum;

}
