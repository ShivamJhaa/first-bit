#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> adjList;

    public:
    Graph()
    {

    }
    void addEdge(T u,T v,bool bidirect=true)
    {
        adjList[u].push_back(v);

        if (bidirect)
        {
            adjList[v].push_back(u);
        }
    }

    //BFS function to check whether the given graph is cyclic or not

    bool isCyclicBFS(T src)
    {
        map<T,bool>visited;
        map<T,T>parent;
        queue<T>q;

        q.push(src);
        visited[src]=true;
        parent[src]=src;

        while(!q.empty())
        {
            T node =q.front();
            q.pop();

            //Iterate over the neighbours of that node

            for (auto neighbour:adjList[node])
            {
                if (visited[neighbour]==true && parent[node]!=neighbour)
                return true;

                else if(!visited[neighbour]) {
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }

   

    
};

int main()
{

    Graph<int>g;

    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,3);
    g.addEdge(2,3);

    if (g.isCyclicBFS(1))
    cout<<"Yes It is cyclic"<<"\n";
    else 
    cout<<"No,its not cyclic"<<"\n";

    

    return 0;
}