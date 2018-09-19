//先试网络流跑最大流
struct Mul
{
    bool used[MAXN];
    int G[MAXN][MAXN],match[MAXN][MAXN];
    int num[MAXN];//右最大匹配数
    int uN,vN;
    bool dfs(int u)
    {
        for(int v=0;v<vN;++v)
            if(G[u][v] && !used[v])
            {
                used[v]=true;
                if(match[v][0]<num[v])
            }
    }
};
