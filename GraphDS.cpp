#include<iostream>
#include<bits/stdc++.h> 
using namespace std ;

class Graph 
{
  int no_of_vertices ; 
  list <int> * adjList ;
   bool * visited ; 
public : 
       
        Graph (int V) ; 
        void addEdge(int src , int dst ) ; 
        void  BFS(int src); 
        void  DFS(int src);
        void  DFT();
        void  BFT(); 
        bool isForest(int src) ; 
        void DFSRecursive(int src) ; 
        void initializeVisitedArray(); 
  
};

void Graph :: initializeVisitedArray()
{
    for(int i =0 ; i < no_of_vertices ; i++)
        visited[i] = false ; 
}   

Graph :: Graph (int V) 
{
  this->no_of_vertices = V; 
  adjList = new list<int> [no_of_vertices] ;
  
  visited = new bool[no_of_vertices]; 
  for(int i = 0 ; i < no_of_vertices ; i++) visited[i] = 0 ;
}

void Graph ::  addEdge(int src , int dst )
{
  adjList[src].push_back(dst); 
  adjList[dst].push_back(src); 
}


void Graph ::  BFS(int src)
{
  visited[src] = true ; 
  queue<int> q ;
  q.push(src) ;
  while(!q.empty())
  {
      int temp ;
      temp = q.front() ; q.pop(); 
      cout << temp << " "; 
      for(int & i : adjList[temp])
      {
          if(visited[i] == false)
          {
              visited[i] = true ; 
              q.push(i); 
          }
      }
  }
}
  
void Graph ::  DFSRecursive(int src)
{
    cout << src <<" "; 
    visited[src] = true ;
    for(int &i : adjList[src])
        if(visited[i] == false)
            DFSRecursive(i); 
}

void Graph ::  DFS(int src)
{
  visited[src] = true ; 
  stack<int> s ;
  s.push(src) ;
  while(!s.empty())
  {
      int temp ;
      temp = s.top() ; s.pop(); 
      cout << temp << " "; 
      for(int & i : adjList[temp])
      {
          if(visited[i] == false)
          {
              visited[i] = true ; 
              s.push(i); 
          }
      }
  }
} 

void Graph ::  DFT()
{
    for(int i =0 ; i < no_of_vertices ; i++)
    {
        if(visited[i] == false )
            DFS(i); 
    }
}

bool Graph ::  isForest(int src)
{
    DFS(src); 
    for(int i = 0 ; i < no_of_vertices ; i++)
    {
        if(visited[i] == false)
            return true ; 
    }
    return false ;
}



int main()
{
    Graph g1(8) ; 
    g1.addEdge(0,1); 
    g1.addEdge(0,2); 
    g1.addEdge(1,3); 
    g1.addEdge(1,4); 
    g1.addEdge(5,6); 
    g1.addEdge(5,7); 
    
   g1.initializeVisitedArray(); 
   g1.DFSRecursive(0);
   cout << "\n"; 
   g1.initializeVisitedArray(); 
   g1.DFSRecursive(0);
   /*  if(g1.isForest(0))
        cout <<"IS FOREST " ; */
    //g1.DFT(); 
    return 0 ; 
}
