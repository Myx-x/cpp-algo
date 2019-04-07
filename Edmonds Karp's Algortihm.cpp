#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vi> adjList;
int maxflow=0;
int node, edge, source, sink, flow;
int parentMap[1000];
int res[1000][1000];

/*
7 11 0 6
0 1 3
0 3 3
1 2 4
2 3 1
2 0 3
2 4 2
3 4 2
3 5 6
4 1 1
4 6 1
5 6 9
*/

void resPrint()
{
    for(int i=0;i<node;i++)
    {
        for(int j=0;j<node;j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    printf("--------------------\n");
}

void parentPrint()
{
    for(int i=0;i<node;i++)
        printf("%d <- %d\n", i, parentMap[i]);
}

void adjPrint()
{
    for(int i=0;i<adjList.size()-1;i++)
    {
        printf("%d :", i);
        for(int j=0;j<adjList[i].size();j++)
            printf("(%d, (%d, %d)) ", adjList[i][j], res[i][adjList[i][j]], res[adjList[i][j]][i]);
        printf("\n");
    }
}

void augment(int n, int minEdge)
{
    if(n==source)
    {
        flow=minEdge;
        return;
    }
    else if(parentMap[n]!=-1)
    {
        augment(parentMap[n], min(minEdge, res[parentMap[n]][n]));
        res[parentMap[n]][n]-=flow;
        res[n][parentMap[n]]+=flow;
        //resPrint();
    }
    
}

int main()
{  
    printf("[Node, Edge, Source, Sink]: ");
    scanf("%d%d%d%d", &node, &edge, &source, &sink);
    adjList.resize(node+1);
    memset(res, 0, sizeof(res));

    printf("[Node 1, Node 2, Edge Capacity]:\n");
    for(int i=0;i<edge;i++)
    {
        int n1, n2, cap;
        scanf("%d%d%d" , &n1, &n2, &cap);
        adjList[n1].push_back(n2);
        res[n1][n2]=cap;
    }

    while(1)
    {
        flow=0;
        
        memset(parentMap, -1, sizeof(parentMap));
        queue<int> q;
        q.push(source);

        bool vis[1000];
        memset(vis, false, sizeof(vis));
        vis[source]=true;

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();

            for(int i=0;i<adjList[curr].size();i++)
            {
                int v=adjList[curr][i];
                if(!vis[v] && res[curr][v]>0)
                {
                    q.push(v);
                    vis[v]=true;
                    parentMap[v]=curr;
                }
            }

        }

        //Augment Path (Recursive backtracking)
        augment(sink, 1e9);
        
        //No more flow, break
        if(flow==0) break;

        //..else then add flow to maxflow.
        maxflow+=flow;
        printf("Flow equals to %d, Maxflow is now %d\n", flow, maxflow);

    }
    printf("Maxflow equals to %d\n", maxflow);

}