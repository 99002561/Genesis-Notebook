#include <stdio.h>
#include "../include/bitmask.h"
#include <stdbool.h>
int set1 (int bit,int pos)
{
    bit |= (1 << pos);
    return bit;
}

int reset(int bit)
{
    return(bit*0);
}
int flip(int bit)
{
    int temp=~bit;
    return temp;
}
void isKthBitSet(int n, int k)
{
    if (n & (1 << (k - 1)))
        printf( "\nSET");
    else
        printf("\nNOT SET");
}


