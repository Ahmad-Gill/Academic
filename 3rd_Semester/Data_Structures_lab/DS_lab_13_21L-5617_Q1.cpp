//
//  main.cpp
//  DAT_lab_12
//
//  Created by Ahmad Gill on 12/5/22.
//
/*
#include<iostream>
#include<List>
using namespace
std;
class Graph
{
    int v; // No. of vertices
    list<int> *adj; // adjacency lists
    bool* visited;
public:
    Graph(int n)
    {
        v = n;
        adj = new list<int>[n];
    }
    void TakeInput(int s, int d)
    {
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    
    void ExploreFunction(int start)
    {
        visited = new bool[v];
        for (int i = 0; i < v; i++)
            visited[i] = false;

        list<int> queue;

        visited[start] = true;
        queue.push_back(start);

        list<int>::iterator i;

        while (!queue.empty()) {
            int currVertex = queue.front();
           // cout << "Visited " << currVertex << " ";
            queue.pop_front();
            cout<<currVertex<<"-->";
            for (i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i) {
                int adjVertex = *i;
                cout<<*i<<" ";
                if (!visited[adjVertex]) {
                   
                    visited[adjVertex] = true;
                    queue.push_back(adjVertex);
                }
            }
            cout<<endl;
        }
    }
    
};

int main()
{
    Graph g(4);
 // Total 5 vertices in graph

    g.TakeInput(0, 1);
    g.TakeInput(0, 2);
    g.TakeInput(1, 2);
    g.TakeInput(2, 0);
    g.TakeInput(2, 3);
    g.TakeInput(3, 3);
    cout<<"Following is Depth First Traversal"<<endl;
    g.ExploreFunction(2);
    
    return 0;
}
*/
