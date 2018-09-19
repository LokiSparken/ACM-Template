// O(v^2)
struct Prim
{
    int vis[maxn],d[maxn],cost[maxn][maxn],n;
    void init(int n)
    {
        this->n=n;
        memset(d,0x3f,sizeof(d));
        memset(cost,0x3f,sizeof(cost));
        memset(vis,false,sizeof(vis));
    }
    int prim(int s)
    {
        d[s]=0; int ans=0;
        while(1)
        {
            int v=-1;
            for(int u=1;u<=n;++u)
                if(!vis[u] && (v==-1 || d[u]<d[v])) v=u;
            if(v==-1) break;
            vis[v]=true, ans+=d[v];
            for(int u=1;u<=n;++u)
                d[u]=min(d[u],cost[v][u]);
        }
        return ans;
    }
};
