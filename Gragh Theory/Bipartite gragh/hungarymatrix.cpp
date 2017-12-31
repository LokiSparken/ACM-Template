/*
 *邻接矩阵
 *初始化G[][]两边顶点划分
 *G[i][j]表示i->j有向边（左向右）
 *G无边相连则初始化为0
 *复杂度O(VE)
 *编号从0开始
 */
struct HungaryM
{
    bool used[MAXN];
    int G[MAXN][MAXN],match[MAXN];
    int uN,vN;//左点数，右点数
    bool dfs(int u)
    {
        for(int v=0;v<vN;++v)
            if(G[u][v] && !used[v])
            {
                used[v]=true;
                if(match[v]==-1 || dfs(match[v]))
                {
                    match[v]=u;
                    return true;
                }
            }
        return false;
    }
    int hungary()
    {
        int ans=0;
        memset(match,-1,sizeof(match));
        for(int u=0;u<uN;++u)
        {
            memset(used,false,sizeof(used));
            if(dfs(u)) ++ans;
        }
        return ans;
    }
};
