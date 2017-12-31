typedef pair<int,int> P;
struct Spfa
{
    vector<pair<int,int> > G[MAXN];
    bool vis[MAXN];
    int inq[MAXN],d[MAXN];
    void init()
    {
        for(int i=0;i<=MAXN;++i) G[i].clear();
        memset(vis,false,sizeof(vis));
        memset(inq,0,sizeof(inq));
        memset(d,0x3f,sizeof(d));
    }
    void add_edge(int u,int v,int cost)
    {
        G[u].push_back(make_pair(cost,v));
    }
    int spfa(int s)
    {
        queue<int> q;
        d[s]=0;
        q.push(s);
        ++inq[s];
        vis[s]=true;
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
                    if(!vis[u])
                    {
                        q.push(u);
                        ++inq[u];
                        vis[u]=true;
                    }
                }
            }
            if(inq[v]>N) return -1;     //有负圈
        }
        if(d[N]==INF) return -2;        //不可达
        return d[N];
    }
};
