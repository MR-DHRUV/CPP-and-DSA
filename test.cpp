#include <bits/stdc++.h>
using namespace std;

bool bfs(int s, int t,vector<vector<int>>&graph,int parent[],int n)
    {
        vector<bool>visited(n+1,false);
        queue<int>q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            visited[u]=true;
            for(int i=1;i<=n;i++)
            {
                if(graph[u][i]>0 && visited[i]==false)
                {
                    parent[i]=u;
                    q.push(i);
                    
                    if(i==t)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
        
    }
    int findMaxFlow(int n,int m,vector<vector<int>> edge)
    {
        vector<vector<int>>graph(n+1,vector<int>(n+1,0)) ;
        
        for(int i=0;i<m;i++)
        {
            graph[edge[i][0]][edge[i][1]]+=edge[i][2] ;
            graph[edge[i][1]][edge[i][0]]+=edge[i][2];
        }
        
        int parent[n+1];
        int ans=0;
        int s=1,t=n;
        while(bfs(1,n,graph,parent,n))
        {
            int max_flow=INT_MAX;
            for(int v=t;v!=s;v=parent[v])
            {
                int u=parent[v];
                max_flow=min(max_flow,graph[u][v]) ;
                
            }
            ans=ans+max_flow ;
            
            for(int v=t;v!=s;v=parent[v])
            {
                int u=parent[v];
                graph[u][v]-=max_flow;
                graph[v][u]+=max_flow ;
                
            }
        }
        
        return ans ;
    }

int main()
{
  
    
    return 0;
}