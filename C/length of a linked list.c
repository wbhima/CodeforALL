#include <stdio.h>

#include <stdlib.h>

typedef struct list 
{
        int data;
        struct list * next;
}
node;

//global variable to store length
int l = 0;

int main()
{
        node * head = NULL, * temp, * temp1;
        int len, choice, count = 0, key;
        //building the link list 
        do
        {
                temp = (node * ) malloc(sizeof(node));
                if (temp != NULL) 
                {
                        printf("\nEnter the element in the list : ");
                        scanf("%d", & temp -> data);
                        temp -> next = NULL;
                        if (head == NULL) 
                        {
                                head = temp;
                        }
                  else
                        {
                                temp1 = head;
                                while (temp1 -> next != NULL)
                                {
                                        temp1 = temp1 -> next;
                                }
                                temp1 -> next = temp;
                        }
                }
          else
                {
                        printf("\nMemory not avilable...node allocation is not possible");
                }
                printf("\nIf you wish to add m ore data on the list enter 1 : ");
                scanf("%d", & choice);
        } 
  while (choice == 1);

        len = length(head);
        printf("The list has a total of %d no of nodes", l);

        return 0;
}

//recursive function to find length
int length(node * temp) 
{
        if (temp == NULL)
                return l;
        else
        {
                l = l + 1;
                length(temp -> next);
        }
}
