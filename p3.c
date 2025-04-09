#include<stdio.h>

int main()
{
    int n,i=1,sum=1;
    printf("Enter a number ");
    scanf("%d",&n);
    while(i<=n)
    {
        sum=sum+sum;
        i=i+1;
    }
    printf("The required answer is:--- %d ",sum);
}