//Chaning   [ Closed Hashing ( Open Addressing ) ]

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//Function for sorted Insert in an Array of Linkedlist
void SortedInsert(struct Node **H, int x)
{
    struct Node *temp, *q = NULL , *p = *H;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;

    if(*H == NULL)
        *H = temp;
    
    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p -> next;
        }
        if(p == *H)
        {
            temp -> next = *H;
            *H = temp;
        }
        else{
            temp -> next = q -> next;
            q -> next = temp;
        }
    }
}

//Hash Function used
int hash(int key)
{
    return key % 10;
}

//Function to Insert in a Hash Table
void Insert(struct Node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index],key);
}

// Search ELement in Hash Table
struct Node *Search(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p -> data)
            return p;
        p = p -> next;
    }
    return NULL;
}

// Delete Key From Hash Table
void Delete(struct Node *p,struct Node **q, int key)
{
    struct Node *prev = p, *curr = p;

    if(curr -> data == key)
    {   prev = curr;
        curr = curr -> next;
        free(prev);
        prev = NULL;
        *q = curr;
    }
    else{
        while(curr && curr->next)
        {
            curr = curr -> next;
            if(curr -> data == key)
            {
                prev -> next = curr -> next;
                free(curr);
                curr = NULL;
            }
            prev = prev -> next;
        }
    }
}

// Print Elements of Hash Table
void print(struct Node *p)
{
    int i = 0;
    
    while(p != NULL)
    {
        printf("chain[%d]--> %d     \t",i,p->data);
        p = p->next;
        i++;
    }
    printf("NULL");
}

int main()
{
    struct Node *HT[10];                            //Array of Pointers
    struct Node *temp;
    int i;

    //for initialising to NULL
    for(i = 0; i<10 ; i++)
        HT[i] = NULL;

    //Insert in a HASH TABLE
    Insert(HT,12);
    Insert(HT,23);
    Insert(HT,35);
    Insert(HT,92);
    Insert(HT,11);
    Insert(HT,50);
    Insert(HT,44);
    Insert(HT,16);
    Insert(HT,7);
    Insert(HT,48);
    Insert(HT,8);
    Insert(HT,98);
    Insert(HT,99);
    Insert(HT,10);
    Insert(HT,33);
    Insert(HT,58);
    Insert(HT,13);
    Insert(HT,77);

    printf("\nElements in Hash Table\n\n");
    for(int i = 0; i<10 ; i++)
    {   
        printf("Index[%d]  -->  ",i);
        print(HT[i]);
        printf("\n");
    }

    printf("\n------------------------------------\n");
    
    printf("\nSearching of keys in Hash Table\n\n");

    temp = Search(HT[hash(23)],23);
    temp ? printf("%d Key Found!!!\n",temp -> data) : printf("-1 Key Not Found!!!\n");

    printf("\n");

    //Searching key in Hash Table

    temp = Search(HT[hash(9)],9);
    temp ? printf("%d Key Found!!!\n",temp -> data) : printf("-1 Key Not Found!!!\n");

    printf("\n------------------------------------\n");

    // Deleting key from Hash Table

    Delete(HT[hash(33)],&HT[hash(33)],33);       //Last Element
    Delete(HT[hash(48)],&HT[hash(48)],48);       //Middle Element
    Delete(HT[hash(44)],&HT[hash(44)],44);       //First Element

    printf("\nElements in Hash Table After Performing Deletion\n\n");
    for(int i = 0; i<10 ; i++)
    {   
        
            printf("Index[%d]  -->  ",i);
            print(HT[i]);
            printf("\n");
    }

    return 0;
}