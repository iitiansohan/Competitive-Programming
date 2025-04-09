#include<stdio.h>

int main()
{
    int n,count=0,n1=n,i=1;
    printf("Enter a number ");
    scanf("%d",&n);
    while(n>0)
    {
        n=n-i;
        i+=2;
        count++;
    }
   printf("%d ",count );  
}