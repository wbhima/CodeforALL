Banker’s Algorithm 

#include<stdio.h>
#include<conio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();
void show();
void cal();
int main()
{
int i,j;
printf("********** Banker's Algo ************\n");
input();
show();
cal();
getch();
return 0;
}
void input()
{
int i,j;
printf("Enter the no of Processes\t");
scanf("%d",&n);
printf("Enter the no of resources instances\t");
scanf("%d",&r);
printf("Enter the Max Matrix\n");
for(i=0;i<n;i++)< span="" style="box-sizing: border-box;">
{
for(j=0;j<r;j++)< span="" style="box-sizing: border-box;">
{
scanf("%d",&max[i][j]);
}
}
printf("Enter the Allocation Matrix\n");
for(i=0;i<n;i++)< span="" style="box-sizing: border-box;">
{
for(j=0;j<r;j++)< span="" style="box-sizing: border-box;">
{
scanf("%d",&alloc[i][j]);
}

}
printf("Enter the available Resources\n");
for(j=0;j<r;j++)< span="" style="box-sizing: border-box;">
{
scanf("%d",&avail[j]);
}
}
void show()
{
int i,j;
printf("Process\t Allocation\t Max\t Available\t");
for(i=0;i<n;i++)< span="" style="box-sizing: border-box;">
{
printf("\nP%d\t ",i+1);
for(j=0;j<r;j++)< span="" style="box-sizing: border-box;">
{
printf("%d ",alloc[i][j]);
}
printf("\t");
for(j=0;j<r;j++)< span="" style="box-sizing: border-box;">
{
printf("%d ",max[i][j]);
}
printf("\t");
if(i==0)
{
for(j=0;j<r;j++)< span="" style="box-sizing: border-box;">
printf("%d ",avail[j]);
}
}
}
void cal()
{
int finish[100],temp,need[100][100],flag=1,k,c1=0;
int safe[100];
int i,j;
for(i=0;i<n;i++)< span="" style="box-sizing: border-box;">
{
finish[i]=0;
}
//find need matrix
for(i=0;i<n;i++)< span="" style="box-sizing: border-box;">
{
for(j=0;j<r;j++)< span="" style="box-sizing: border-box;">

{
need[i][j]=max[i][j]-alloc[i][j];
}
}
printf("\n");
while(flag)
{
flag=0;
for(i=0;i<n;i++)< span="" style="box-sizing: border-box;">
{
int c=0;
for(j=0;j<r;j++)< span="" style="box-sizing: border-box;">
{
if((finish[i]==0)&&(need[i][j]<=avail[j]))
{
c++;
if(c==r)
{
for(k=0;k<r;k++)< span="" style="box-sizing: border-box;">
{
avail[k]+=alloc[i][j];
finish[i]=1;
flag=1;
}
printf("P%d->",i);
if(finish[i]==1)
{
i=n;
}
}
}
}
}
}
for(i=0;i<n;i++)< span="" style="box-sizing: border-box;">
{
if(finish[i]==1)
{
c1++;
}
else
{
printf("P%d->",i);
}

}
if(c1==n)
{
printf("\n The system is in safe state");
}
else
{
printf("\n Process are in dead lock");
printf("\n System is in unsafe state");
}
}
