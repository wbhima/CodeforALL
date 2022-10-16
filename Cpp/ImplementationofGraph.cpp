#include <bits/stdc++.h>
using namespace std;

template <typename T>

class graph{

public:
    // make a adjacency list 
    unordered_map< T , list<T> > adj;

    void addEdge(T u, T v , bool direction){
        // direction = 0 -> undirected
        // direction = 1 -> directed 

        // create a edge from u to v
        adj[u].push_back(v);

        // if graph is undirected graph
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j : i.second){
                cout<<j<<", ";
            }
            cout<<endl; 
        }
    }



};


int main(){

    int n;
    cout<<"Enter no of nodes: ";
    cin>>n;
    int m ;
    cout<<"Enter no of edges: ";
    cin>>m;

    // create a object of class graph
    graph<int> g;
    for(int i =0;i<n;i++){
        int u,v;
        cin>>u>>v;
        // creating graph -- undirected graph
        g.addEdge(u,v,0);
    }

    return 0;
}

// Input
// 5 6
// 0 1 
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4

// Output
// Adjacency List 
// 4 -> 3, 
// 3 -> 2, 1, 4, 
// 2 -> 1, 3, 
// 1 -> 0, 2, 3, 
// 0 -> 1, 
