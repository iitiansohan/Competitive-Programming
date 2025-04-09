#include<stdio.h>
int main()
{
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    int rev=0,n1=n;
    while(n!=0)
    {
        rev=(rev*10)+(n%10);
        n/=10;

    }
    
    if(rev==n1)
    {
        printf("The entered number is palindrome");
    }
    else
    {
        printf("The entered number is not palindrome");
    }
}
    