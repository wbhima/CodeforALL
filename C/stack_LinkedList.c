#include<stdlib.h>
#include<stdio.h>

typedef struct stack_linkedlist {
    int val;
    struct stack_linkedlist * next;
} MinStack;

MinStack * top;

MinStack* minStackCreate() {
    MinStack * temp= malloc(sizeof(MinStack));
    temp->next= NULL;
    top= temp;
    return temp;
}

void minStackPush(MinStack* obj, int val) {
    MinStack * temp = malloc(sizeof(MinStack));
    temp->val= val;
    top->next= temp;
    temp->next= NULL;
    top=top->next;
}

void minStackPop(MinStack* obj) {
    MinStack * temp =obj;
    while(temp->next!=top){
        temp=temp->next;
    }
    temp->next= NULL;
    top=temp;
}

int minStackTop(MinStack* obj) {
    return top->val;
}

int minStackGetMin(MinStack* obj) {
    MinStack * temp =obj->next;
    int min= temp->val;
    while(temp!=NULL){
        if(min > temp->val){
            min = temp->val;
        }
        temp=temp->next;
    }
    return min;
}

void minStackFree(MinStack* obj) {
    obj->next= NULL;
    free(obj);
}
void display_list( MinStack* obj){
    MinStack *temp;
    temp =obj->next;
    while(temp!= NULL){
        printf("%d  ", temp->val);
        temp=temp->next;
    }
    printf("\n");
    
}
int main(){
    MinStack* obj = minStackCreate();
    minStackPush(obj, -2);
    minStackPush(obj, 0);
    minStackPush(obj, -3);
    display_list(obj);
    int param_2 = minStackGetMin(obj);
    printf("%d\n", param_2);
    minStackPop(obj);
    display_list(obj);
    int param_3 = minStackTop(obj);
    printf("%d", param_3);
    int param_4 = minStackGetMin(obj);
    printf("%d", param_4);
    minStackFree(obj);
}
