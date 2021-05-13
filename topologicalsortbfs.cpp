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

    //Topological sort using bfs player

    void bfstopological()
    {
        map<T,bool>visited;
        map<T,int>indegree;
        queue<T>q;

        //Initiating the maps

        for (auto i:visited)
        {
            T node=i.first;
            visited[node]=false;
            indegree[node]=0;
        }

        //Storing the indegree of all the nodes

        for (auto i:adjList)
        {
            T node=i.first;
            for (auto j:adjList[node])
            {
                indegree[j]++;
            }
        }

        //Find out all nodes with 0 indegree

        for (auto i:adjList)
        {
            T node =i.first;
            if (indegree[node]==0)
            {
                q.push(node);
            }
        }

        //Start with our bfs algorithm

        while(!q.empty())
        {
            T temp=q.front();
            q.pop();
            cout<<temp<<" ";
            //Find all the neighbour and reduce their n degree

            for (auto neighbour:adjList[temp])
            {
                indegree[neighbour]--;

                if (indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }
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
    g1.addEdge("A","J",false);
    g1.addEdge("Am","D",false);
    g1.addEdge("D","J",false);
    g1.addEdge("M","J",false);
    g1.addEdge("M","B",false);
    g1.addEdge("A","J",false);
    g1.addEdge("D","B",false);
    g1.addEdge("X","Y",false);

    g1.bfstopological();

    

    return 0;
}