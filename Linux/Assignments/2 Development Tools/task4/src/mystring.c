#include "../include/mystring.h"
 

unsigned int my_strlen(char *p)
{
    unsigned int count = 0;

 

    while(*p!='\0')
    {
        count++;
        p++;
    }

 

    return count;
}

 

char *my_strcpy(char *destination, char *source)
{
    char *start = destination;

 

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

 

    *destination = '\0';
    return start;
}

 

char *my_strcat(char *strg1, char *strg2)
{
    char *start = strg1;

 

    while(*strg1 != '\0')
    {
        strg1++;
    }

 

    while(*strg2 != '\0')
    {
        *strg1 = *strg2;
        strg1++;
        strg2++;
    }

 

    *strg1 = '\0';
    return start;
}

 

int my_strcmp(char *strg1, char *strg2)
{
    while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 )
    {
        strg1++;
        strg2++;
    }

 

    if(*strg1 == *strg2)
    {
        return 0; // strings are identical
    }

 

    else
    {
        return *strg1 - *strg2;
    }
}
