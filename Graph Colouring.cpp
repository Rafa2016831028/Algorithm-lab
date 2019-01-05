/*
5 6
0 1
0 2
1 2
1 3
2 3
3 4
*/
#include<bits/stdc++.h>
using namespace std;
int V;
vector<int> *adj;

void addEdge(int v,int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void greedyColouring()
{
    int result[V];
    result[0] = 0;

    for(int u =1; u<V ;u++)
    {
        result[u] = -1;
    }

    bool available[V] ;

    for(int cr = 0; cr<V ;cr++)
    {
        available[cr] =false;
    }

    for(int u =1; u<V; u++)
    {
        vector<int>::iterator i;
        for(i =adj[u].begin() ; i!= adj[u].end() ; ++i)
        {
            if(result[*i] != -1)
                available[result[*i]] = true;
        }

        int cr;
        for(cr =0; cr<V; cr++)
        {
            if(available[cr] == false)
                break;
        }
        result[u] =cr;
        for(i =adj[u].begin() ; i!= adj[u].end() ; ++i)
        {
            if(result[*i] != -1)
                available[result[*i]] = false;
        }
    }

    for(int u =0 ; u<V ;u++)
    {
        cout<<"vertex  "<<u<<" --> colour "<<result[u]<<endl;
    }
}
int main()
{
    int edge;
    scanf("%d %d",&V,&edge);
    adj = new vector<int>[V];
    while(edge--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        addEdge(a,b);
    }
    greedyColouring();
    return 0;
}
