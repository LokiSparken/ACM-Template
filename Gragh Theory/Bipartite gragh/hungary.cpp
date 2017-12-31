struct Hungary
{
    vector<int> G[MAXN];
    int match[MAXN];
    bool used[MAXN];
    int V;

    void init(int N)
    {
        this->V=N;
        for(int i=0;i<=V;++i) G[i].clear();
    }
    void add_edge(int u,int v)
    {
        G[u].push_back(v);
    }
    bool dfs(int v)
    {
        for(int i=0;i<G[v].size();++i)
        {
            int u=G[v][i];
            if(!used[u])
            {
                used[u]=true;
                if(match[u]==-1 || dfs(match[u]))
                {
                    match[u]=v;
                    return true;
                }
            }
        }
        return false;
    }
    int hungary()
    {
        int ans=0;
        memset(match,-1,sizeof(match));
        for(int v=1;v<=V;++v)
        {
            memset(used,false,sizeof(used));
            if(dfs(v)) ++ans;
        }
        return ans;
    }
};
