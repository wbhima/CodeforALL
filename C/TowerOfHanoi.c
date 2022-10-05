// Towers of Hanoi problem using recursion


#include<stdio.h>
void main()
{
int n;
char A='A',B='B',C='C';
void hanoi(int, char, char, char);

printf ("Enter Number of Disks:");
scanf("%d",&n);
printf("\n\n Tower of Hanoi problem with %d disks\n",n);
printf("Sequence is :\n");
hanoi (n, A, B, C);
printf ("\n");
}
void hanoi(int n, char A, char B, char C)
{
if (n!=0)
{
hanoi (n-1,A,C,B);
printf ("Move disk %d from %c to %c\n",n,A,C);
hanoi (n-1,B,A,C);
}
}
