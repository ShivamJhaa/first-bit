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
    //Dfs function to chcek whther the given graph contains back-edge or not
    bool DfsHelper(T node,map<T,bool>&visited,map<T,bool>&inStack)
    {
        //Process the current node
        visited[node]=true;
        inStack[node]=true;

        //Explore the neighbour
        for (auto neighbour:adjList[node])
        {
            //There are two conditions right now,either the neighbour of the curent node have a cycle present or it the node of cycle
            if ((!visited[neighbour] && DfsHelper(neighbour,visited,inStack)) || inStack[neighbour])
            {
                return true;
            }
        }
        inStack[node]=false;

        return false;
    }

    bool isCyclicDfs()
    {
        map<T,bool>visited;
        map<T,bool>inStack;

        for (auto i:adjList)
        {
            T node =i.first;
            if (!visited[node])
            {
                bool CyclePresent=DfsHelper(node,visited,inStack);
                if (CyclePresent)
                return true;
            }
        }
        return false;
    }
};

int main()
{

    Graph<int>g;

    g.addEdge(0,2,false);
    g.addEdge(0,1,false);
    g.addEdge(2,3,false);
    g.addEdge(2,4,false);
    g.addEdge(3,0,false);
    g.addEdge(4,5,false);
    g.addEdge(1,5,false);


    if (g.isCyclicDfs())
    cout<<"Yes It is cyclic"<<"\n";
    else 
    cout<<"No,its not cyclic"<<"\n";

    

    return 0;
}