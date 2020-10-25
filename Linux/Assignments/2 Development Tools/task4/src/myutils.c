#include<stdio.h>
#include "../include/myutils.h"
#include <stdarg.h>


int  factorial(int num){
int i,fact=1;
if(num<0)
	printf("\nerror factorial of a negative num");
else
	for(i=1;i<=num;++i){
	fact*=i;
	}
	return fact;
	}

int isprime(int num){
int i,flag=0;
for(i=2;i<=num/2;++i){
if(num%i==0){
flag=1;
break;
}
}
if(num==1){
printf("\n1 is not prime num");
}
else{
	if(flag==0){
printf("\n %d is a prime num",num);
}
	else{
printf("\n%d is not a prime num",num);
}
}
}

int  ispalindrome(int num){
int reversedn=0,reminder,originaln;
originaln=num;
while(num!=0){
reminder=num%10;
reversedn=reversedn*10+reminder;
num/=10;
}
if(originaln==reversedn)
	printf("\n%d is a palindrome",originaln);
else
	printf("\n%d is not a palindrome",originaln);

}



int sum(int arg_count,...)
{
    int i;
    int first, a;


    va_list ap;
    va_start(ap, arg_count);
  
int sum=0;
    
    for (i = 1; i <= arg_count; i++) 
        sum+=va_arg(ap,int);

    va_end(ap);
    return sum;
}


