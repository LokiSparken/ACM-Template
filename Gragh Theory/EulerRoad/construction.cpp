stack<int> s;
void dfs(int u)
{
    for(auto &v:G[u])
    {
        if(!vis[u][v])
        {
            vis[u][v]=1;// 有向图
            dfs(v);
        }
    }
    s.push(u);
}