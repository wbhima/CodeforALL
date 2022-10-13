#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    float x,sum=1,t=1;
    printf("Enter the value of x: ");
    scanf("%f",&x);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    x=x*3.14159/180;
    for (i=1;i<=n; i++)
    {
        t=t*(-1)*x*x/(2*i*(2*i-1));
        sum=sum+t;
    }
    printf("The value of cosx is %f",sum);
    return 0;
}
