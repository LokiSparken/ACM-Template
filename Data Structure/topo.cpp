struct Topo
{
    vector<int> G[MAXN];
    int in[MAXN],ans[MAXN];//ans得到拓扑排序后点编号顺序
    int tot;
    void init(int N)
    {
        for(int i=0;i<=N;++i) G[i].clear();
        memset(in,0,sizeof(in));
        memset(ans,0,sizeof(ans));
        tot=0;
    }
    void addEdge(int u,int v)
    {
        G[u].push_back(v);
        ++in[v];
    }
    void topo()
    {
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i=1;i<=N;++i)
            if(!in[i]) q.push(i);
        while(!q.empty())
        {
            int u=q.top();q.pop();
            ans[total++]=u;
            for(int i=0;i<G[u].size();i++)
            {
                int v=G[u][i];
                if((--in[v])==0)
                    q.push(v);
            }
        }
    }
};
