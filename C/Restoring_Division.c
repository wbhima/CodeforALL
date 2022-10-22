#include<stdio.h>
#include<conio.h>
#include<math.h>

int a=0,b=0,c=0,com[5]={1,0,0,0,0},s=0;
int anum[5]={0},anumcp[5] ={0},bnum[5]={0};
int acomp[5]={0},bcomp[5]={0},rem[5]={0},quo[5]={0},res[5]={0};

void binary(){
     a = fabs(a);
     b = fabs(b);
     int r, r2, i, temp;
     for(i = 0; i < 5; i++){
           r = a % 2;
           a = a / 2;
           r2 = b % 2;
           b = b / 2;
           anum[i] = r;
           anumcp[i] = r;
           bnum[i] = r2;
           if(r2 == 0){
                bcomp[i] = 1;
           }
           if(r == 0){
                acomp[i] =1;
           }
     }
   //part for two's complementing
   c = 0;
   for( i = 0; i < 5; i++){
           res[i] = com[i]+ bcomp[i] + c;
           if(res[i]>=2){
                c = 1;
           }
           else
                c = 0;
           res[i] = res[i]%2;
     }
   for(i = 4; i>= 0; i--){
     bcomp[i] = res[i];
   }
}
void add(int num[]){
     int i;
     c = 0;
     for( i = 0; i < 5; i++){
           res[i] = rem[i]+ num[i] + c;
           if(res[i]>=2){
                c = 1;
           }
           else
                c = 0;
           res[i] = res[i]%2;
     }
     for(i = 4; i>= 0; i--){
           rem[i] = res[i];
           printf("%d",rem[i]);
     }
     printf(":");
     for(i = 4; i>= 0; i--){
           printf("%d",anumcp[i]);
     }
}
void shl(){//for shift left
     int i;
     for(i = 4; i > 0  ; i--){//shift the remainder
           rem[i] = rem[i-1];
     }
     rem[0] = anumcp[4];
     for(i = 4; i > 0  ; i--){//shift the remtient
           anumcp[i] = anumcp[i-1];
     }
     anumcp[0] = 0;
     printf("\nSHIFT LEFT: ");//display together
     for(i = 4; i>= 0; i--){
           printf("%d",rem[i]);
     }
     printf(":");
     for(i = 4; i>= 0; i--){
           printf("%d",anumcp[i]);
     }
}

void main(){
     int i;
     printf("\t\tRESTORING DIVISION ALGORITHM");
     printf("\nEnter two numbers to divide: ");
     do{
           printf("\nEnter Dividend: ");
           scanf("%d",&a);
           printf("Enter Divisor: ");
           scanf("%d",&b);
     }while(a>=16 || b>=16);

     printf("\nExpected Quotient = %d", a/b);
     printf("\nExpected Remainder = %d", a%b);
     if(a*b <0){
           s = 1;
     }

     binary();
     printf("\n\nUnsigned Binary Equivalents are: ");
     printf("\nA = ");
     for(i = 4; i>= 0; i--){
           printf("%d",anum[i]);
     }
     printf("\nB = ");
     for(i = 4; i>= 0; i--){
           printf("%d",bnum[i]);
     }
     printf("\nB'+ 1 = ");
     for(i = 4; i>= 0; i--){
           printf("%d",bcomp[i]);
     }
     printf("\n\n-->");
     //division part
     shl();
     for(i=0;i<5;i++){
           printf("\n-->"); //start with subtraction
           printf("\nSUB B: ");
           add(bcomp);
           if(rem[4]==1){//simply add for restoring
                printf("\n-->RESTORE");
                printf("\nADD B: ");
                anumcp[0] = 0;
                add(bnum);
           }
           else{
                anumcp[0] = 1;
           }
           if(i<4)
                shl();

     }
     printf("\n----------------------------");
     printf("\nSign of the result = %d",s);
     printf("\nRemainder is = ");
     for(i = 4; i>= 0; i--){
           printf("%d",rem[i]);
     }
     printf("\nQuotient is = ");
     for(i = 4; i>= 0; i--){
           printf("%d",anumcp[i]);
     }
getch();

}
