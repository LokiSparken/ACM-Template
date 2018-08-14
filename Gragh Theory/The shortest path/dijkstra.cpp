// 时间复杂度：eloge
typedef pair<int,int> P;
struct Dijkstra
{
    vector<P> G[maxn];
    int d[maxn],vis[maxn];
    void init(int n) { for(int i=0;i<=n;++i) G[i].clear(); }
    void addEdge(int u,int v,int cost) { G[u].push_back({cost,v}); }
    void dij(int s)
    {
        memset(d,0,sizeof(int)*(n+5)));
        memset(vis,0,sizeof(int)*(n+5));
        priority_queue<P,vector<P>,greater<P> > q;
        d[s]=0;
        q.push(make_pair(d[s],s));
        while(!q.empty())
        {
            P temp=q.top();q.pop();
            int v=temp.Y;
            if(vis[v]) continue;
            vis[v]=true;
            for(int i=0;i<G[v].size();++i)
            {
                int u=G[v][i].Y,cost=G[v][i].X;
                if(!vis[u] && d[u]>d[v]+cost)
                {
                    d[u]=d[v]+cost;
                    q.push(make_pair(d[u],u));
                }
            }
        }
    }
};
