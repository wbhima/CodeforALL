//Reverse the String Using Stack
 
#include<stdio.h>
#define maxstk 10
void Push(char);
char Pop();
void Peep();

char ArrStk[maxstk];
int top=-1;
void main()
{
char ch;
int i;

printf("Input the String\n");
while((ch=getchar())!='\n')
Push(ch);

/*while(1)
{
scanf("%c",&ch);
if(ch=='\n')
break;
else
Push(ch);
} */

Peep();
printf("The Reverserd  String is--\n");
while((ch=Pop())!='\0')
printf("%c",ch);

}

void Push(char ch)
{
if(top==maxstk-1)
printf("Overflow");
else
ArrStk[++top]=ch;
}

char Pop()
{
char ch;
if(top==-1)
return '\0';
else
{
ch=ArrStk[top];
top--;
}
return ch;
}

void Peep()
{
int i;
if(top==-1)
printf("Empty");
else
{
for(i=maxstk;i>0;i--)
printf("%c",ArrStk[i]);
}
}
