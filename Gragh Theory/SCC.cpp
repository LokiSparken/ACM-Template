struct SCC
{
    vector<int> G[maxn];
    int pre[maxn],low[maxn],sccno[maxn],dfs_clock,scc;
    // scc:强连通分量个数，sccno[i]:缩点后i所在点编号
    stack<int> s;
    void init()
    {
        for(int i=0;i<=n;++i) G[i].clear();
        memset(sccno,0,sizeof(sccno));
        memset(pre,0,sizeof(pre));
        while(!s.empty()) s.pop();
        dfs_clock=scc=0;
    }
    void addEdge(int u,int v) { G[u].push_back(v); }
    void tarjan(int u)
    {
        pre[u]=low[u]=++dfs_clock;
        s.push(u);
        for(int i=0;i<G[u].size();++i)
        {
            int v=G[u][i];
            if(!pre[v])
            {
                tarjan(v);
                low[u]=min(low[u],low[v]);
            }
            else if(!sccno[v]) low[u]=min(low[u],pre[v]);
        }
        if(low[u]==pre[u])
        {
            ++scc;
            while(1)
            {
                int v=s.top();s.pop();
                sccno[v]=scc;
                if(v==u) break;
            }
        }
    }
    void findscc() { for(int i=1;i<=n;++i) if(!pre[i]) tarjan(i); }
};
