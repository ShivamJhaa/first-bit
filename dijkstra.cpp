#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> m;

    public:
    void addEdge(T u,T v,int dist,bool bidirect=true)
    {
        m[u].push_back(make_pair(v,dist));

        if (bidirect)
        {
            m[v].push_back(make_pair(u,dist));
        }
    }
    void printAdj()
    {
        //Let us try to print the adjList
        //Iterate over all the elements of the adjList 
        for (auto i:m)
        {
            cout<<i.first<<" --> ";
            //Iterate over all the list of this node
            for (auto j:i.first)
            {
                cout<<"( "<<j.first<<" , "<<j.second<<" )";
            }
            cout<<endl;
        }
    }
    void dijkstraSSSP(T src)
    {
        unordered_map<T,int>dist;

        //Set each distance as infinity
        for (auto i:dist)
        {
            dist[i.first]=INT32_MAX;
        }

        //Make a set to find out the min distance,in set the sorting is done on the basis of first parameter
        set<pair<int,T>>s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty())
        {
            //Find the pair at the front
            auto p=*(s.begin());
            T node=p.second;
            int nodeDist=p.first;
            s.erase(s.begin());


            //Iterate over all the children of the node
            for (auto childPair:m[node])
            {
                if (nodeDist + childPair.second < dist[childPair.first])
                {
                    //We have to upgrade the distance of the node

                    T dest=childPair.first;
                    auto f=s.find(make_pair(dist[dest],dest))
                    
                    if (f!=s.end())
                    {
                        s.erase(f);
                    }
                    //Insert the new pair

                    dist[dest]=nodeDist+childPair.second;
                    s.insert(dist[dest],dest);
                }
            }

        }
        for (auto j:dist)
        {
            cout<<j.fist<<" is at the distance of "<<j.second<<endl;
        }

    }
    
};

int main()
{

    Graph<int>g;

    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    
    g.dijkstraSSSP(1);

    return 0;
}