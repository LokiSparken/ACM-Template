struct Spfa // O(ke),稀疏图k<2，一般为常数，网格图可hack
{
    vector<pair<int,int> > G[maxn];
    bool vis[maxn];
    int inq[maxn],d[maxn];
    void init()
    {
        for(int i=0;i<=maxn;++i) G[i].clear();
        memset(vis,false,sizeof(vis));
        memset(inq,0,sizeof(inq));
        memset(d,0x3f,sizeof(d));
    }
    void addedge(int u,int v,int cost) { G[u].push_back(make_pair(cost,v)); }
    int spfa(int s)
    {
        queue<int> q;
        d[s]=0, q.push(s), ++inq[s], vis[s]=true;
        while(!q.empty())
        {
            int v=q.front();q.pop();
            vis[v]=false;
            for(int i=0;i<G[v].size();++i)
            {
                int u=G[v][i].Y,cost=G[v][i].X;
                if(d[u]>d[v]+cost)
                {
                    d[u]=d[v]+cost;
                    if(!vis[u]) q.push(u),++inq[u],vis[u]=true;
                }
            }
            if(inq[v]>n) return -1;     //有负圈
        }
        if(d[n]==inf) return -2;        //不可达
        return d[n];
    }
};
