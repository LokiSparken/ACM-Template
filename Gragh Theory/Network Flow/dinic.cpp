struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct Dinic
{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    bool vis[MAXN];
    int d[MAXN],cur[MAXN];
    void init(int n)
    {
        for(int i=0;i<=n;++i) G[i].clear();
        edges.clear();
    }
    void addEdge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BFS()
    {
        memset(vis,false,sizeof(vis));
        queue<int> q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!q.empty())
        {
            int v=q.front();q.pop();
            for(int i=0;i<G[v].size();++i)
            {
                int ecode=G[v][i];
                Edge &e=edges[ecode];
                if(!vis[e.to] && e.cap>e.flow)
                {
                    vis[e.to]=true;
                    d[e.to]=d[v]+1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int DFS(int v,int a)
    {
        if(v==t || a==0) return a;
        int flow=0,f;
        for(int &i=cur[v];i<G[v].size();++i)
        {
            int ecode=G[v][i];
            Edge &e=edges[ecode];
            if(d[v]+1==d[e.to] && (f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[ecode^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int maxFlow(int s,int t)
    {
        this->s=s;this->t=t;
        int flow=0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
};
