//Double Hashing    [ Closed Hashing ( Open Addressing ) ]

//Quadratic Probing    [ Closed Hashing ( Open Addressing ) ]

#include<stdio.h>
#define SIZE 10
#define PRIME 7                             //used in Second Hash Function

//Hash Function
int hash1 (int key)                         //1st Hash Function
{
    return key % SIZE;
}

int hash2 (int key)                         //2nd Hash Function
{
    return (PRIME - (key % PRIME));
}

//Find Free Space In Hash Table
int probe (int H[] , int key)               //Double Hashing
{
    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;
    
    while(H[(index1 + i * index2) % SIZE] != 0)       //Hash Function Used = (( h'(x) = ((h1(x) + i * h2(x)) % SIZE ))   ,where, i = 0 , 1 , 2 , 3 . . . . . . .
        i++;

    return (index1 + i * index2) % SIZE;
}

//Insert ELement in Hash Table
void Insert(int H[] , int key)
{
    int index1 = hash1(key);
   
    if(H[index1] != 0)              //if collision occurs probe
    {
        int newIndex = probe(H,key);
        H[newIndex] = key;
    }
    else
        H[index1] = key;            //if no collision occurs
}

//Search Element in Hash Table
int Search(int H[], int key)
{
    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;
    while(H[(index1 + i * index2) % SIZE ] != key)
    {
        i++;                                            //worst case if space means "0" not found so
        if((index1 + i * index2) % SIZE == 0 )                    //this means all indexes have value therefore 
            return -1;                                  //if i becomes = size && element not found return -1
    }

    return (index1 + i * index2) % SIZE;
}

//Delete key From Hash Table (Re-Hashing)
void Delete(int H[], int key)
{
    int index1= hash1(key);
    int index2 = hash2(key);
    int i = 0, j = 0;
    while(H[(index1 + i * index2) % SIZE] != key)
    {
        i++;
        if((index1 + i * index2) % SIZE == 0)
        {
            printf("\n%d Key not Exist's in Hash Table\n",key);
            break;
        }
    }
    H[(index1 + i * index2) % SIZE] = 0;                              //deleting memory by making it Zero.
    
    int arr[SIZE] = {0};                                        //New arry for rehashing initializing to 0
    for(int i = 0; i < SIZE ; i++)
    {
        if(H[i] != 0)
        {
            arr[j] = H[i];
            j++;
        }
    }

    for(int i = 0; i<SIZE ; i++)                                //reinitializing to 0 Hash Table
    {
        H[i] = 0;
    }

    for(int i = 0; i<j ; i++)                                   //inseting to Hash table from another array (Rehashing)
    {
        Insert(H, arr[i]);
    }
}

//Print Element in Hash Table
void print(int H[])
{
    int i = 0;
    for(int i = 0; i<10; i++)
        printf("HT[%d]  -->  %d\n",i,H[i]);
}

int main()
{
    int HT[10] = {0};
    int res;
    Insert(HT, 3);
    Insert(HT, 10);
    Insert(HT, 93);
    Insert(HT, 13);
    Insert(HT, 65);
    Insert(HT, 6);

    printf("Elements in Hash Table\n\n");
    print(HT);

    res = Search(HT,10);                                    //if Found Print Key Index Else -1
    (res != -1) ? printf("\n%d Key found at Index %d\n",10,res) : printf("\n%D Key Not Found %d\n",10,res);

    Delete(HT,65);                                         //Delete Key From Hash Table
    Delete(HT,93);                                         //Delete Key From Hash Table

    printf("\nElements in Hash Table After Performing Deletion Done Through Re-Hashing\n\n");
    print(HT);                                             //Print after Deleting
    
    
    Insert(HT, 65);                                         //Insert
    Delete(HT,10);                                          //Delete

    printf("\nElements in Hash Table After Performing  INsertion & Deletion Again Final Hash Table\n\n");
    print(HT);

     res = Search(HT,65);                                    //if Found Print Key Index Else -1
    (res != -1) ? printf("\n%d Key found at Index %d\n",65,res) : printf("\n%d Key Not Found %d\n",65,res);

    return 0;
}