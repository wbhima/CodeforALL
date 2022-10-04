#include<stdio.h>

int main(){
    
    int i=1, large= -32768, num;


    while (i<=5)
    {
        printf("\n Enter the number: ");
        scanf("%d", &num);
        large = num>large?num:large;
        i++;
    }
    
    printf("\n The largest of Five numbers entered is: %d", large);


return 0;
}