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

    //DFS topologicL sort
    
    void dfsHelper(T node,map<T,bool>&visited,list<T>&ordering)
    {
        visited[node]=true;

        //call all the unvisited nodes

        for (auto neighbour:adjList[node])
        {
            if (!visited[neighbour])
            {
                dfsHelper(neighbour,visited,ordering);
            }
        }
        //As all the nodes have been visited we can add the elements in our list

        ordering.push_front(node);
    }

    void dfstopologic()
    {
        map<T,bool>visited;
        list<T>ordering;

        for (auto i:adjList)
        {
            T node= i.first;
            if (!visited[node])
            {
                dfsHelper(node,visited,ordering);
            }

        }
        //print all the elements of list

        for (auto i:ordering)
        {
            cout<<i<<"->";
        }
        cout<<endl;

    }
 

    
};

int main()
{

    /*Graph<int>g;

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(4,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.dfs(0);*/
    Graph<string>g1;
    g1.addEdge("A","J");
    g1.addEdge("Am","D");
    g1.addEdge("D","J");
    g1.addEdge("M","J");
    g1.addEdge("M","B");
    g1.addEdge("A","J");
    g1.addEdge("D","B");
    g1.addEdge("X","Y");

    g1.dfstopologic();
    

    return 0;
}