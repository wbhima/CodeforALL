#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node
{
    int data;
    struct node *next;

} node;

node *link = NULL;

void insert_link(int val)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = val;
    p->next = NULL;
    if (link == NULL)
    {
        link = p;
    }
    else
    {
        p->next = link;
        link = p;
    }
    
    
}

node *insert(node *root)
{
    int j = 0;
    while (1)
    {
        printf("\nEnter the adjacancy node number or enter -1 to stop : ");
        scanf("%d", &j);
        if (j == -1)
        {
            break;
        }
        node *p = (node *)malloc(sizeof(node));
        p->data = j;
        p->next = NULL;
        if (root == NULL)
        {
            root = p;
        }
        else
        {
            p->next = root;
            root = p;
        }
    }
    return root;
}

void print(node *p)
{
    while (p != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
}

void DFS_visit(node **graph, int *color, int i)
{
    if (graph[i] != NULL)
    {
        int k = graph[i]->data;
        node *temp = graph[i];
        while (temp != NULL)
        {
            if (color[k] == 0)
            {
                
                color[k] = 1;
                DFS_visit(graph, color, k);
                insert_link(k);
            }
            temp = temp->next;
            if (temp != NULL)
                k = temp->data;
        }
    }
}

void DFS(node **graph, int *color, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            color[i] = 1;
            DFS_visit(graph, color, i);
            insert_link(i);
        }
    }
}

void topology_sort(node **graph,int *color,int n)
{
    DFS(graph,color,n);
    print(link);
}

int main()
{
    node *graph[20];
    int n;
    printf("\nEnetr the number of nodes : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\ninsert the adjaceency nodes in the graph for node %d", i);
        graph[i] = NULL;

        graph[i] = insert(graph[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d->", i);
        print(graph[i]);
        printf("\n");
    }
    int color[n];
    for (int i = 0; i < n; i++)
    {
        color[i] = 0;
    }
    printf("\nTopology sort of the given graph is : \n");
    topology_sort(graph,color,n);
    return 0;
}