#include<stdio.h>

int main()
{
    int n;
    printf("Enter a decimal number");
    scanf("%d",&n);
    int rev=0;
    int mul = 1;
    int rem;
     while (n != 0) {
        rem = n% 2;
        n /= 2;
        rev += rem *mul;
        mul *= 10;
    }
    printf("%d",rev);

}