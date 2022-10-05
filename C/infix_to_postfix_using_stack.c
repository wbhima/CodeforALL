#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top=-1;
void push(char x){
    if(top>=99){
        printf("Overflow..");
    }
    else{
        top++;
        stack[top]=x;
    }
}
char pop(){
    char x;
    if(top==-1){
        printf("Underflow");
        exit(1);
    }
    else{
    x=stack[top];
    top--;
    return x;
    }
}
int isOperator(char sym){
    if(sym =='/'||sym =='+'||sym =='-'||sym =='^'||sym =='*'){
        return 1;
    }
    return 0;
}
int Precedence(char sym){
    if(sym=='^'){
        return 3;
    }
    else if(sym=='/'||sym=='*'){
        return 2;
    }
    else if(sym=='+'||sym=='-'){
        return 1;
    }
    else
        return 0;
}
void convert(char infix[],char postfix[]){
    int i=0,j=0;
    char x,rem;
    push('(');
    strcat(infix,")");
    x=infix[i];
    while(x!='\0'){
        
        if(x=='('){
            push(x);   
        }
        else if(isOperator(x)){
            rem=pop();
            if( (isOperator(x)) && (Precedence(x)<=Precedence(rem))){
               postfix[j]=rem;
                j++;
                rem=pop();
            }
            push(rem);
            push(x);
        }
        else if(isalpha(x)||isdigit(x)){
            postfix[j]=x;
            j++;
        }
        else if(x==')'){
            rem=pop();
            while(rem!='('){
                
                postfix[j]=rem;
                j++;
                rem=pop();
            }
        }
        i++;
        x=infix[i];
    }
    if(top>-1){
        printf("ERR0R");
    }
    postfix[j]='\0';
    
    
}
int main(){
    char infix[100],postfix[100];
    printf("Enter the infix expression:");
    gets(infix);
    convert(infix,postfix);
    printf("The postfix Expression is:");
    puts(postfix);
    return 0;
}