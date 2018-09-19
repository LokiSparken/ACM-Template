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

// print
void print(int u)
{
    for(int v=1;v<=50;++v)
    {
        if(edge[u][v])
        {
            --edge[u][v],--edge[v][u];
            print(v);
            printf("%d %d\n",v,u);
        }
    }
}