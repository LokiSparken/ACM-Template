/*
 *复杂度O(sqrt(n)*E)
 *编号0开始
 */
struct HK
{
    vector<int> G[MAXN];
    int uN;

    bool used[MAXN];
    int Mx[MAXN],My[MAXN];
    int dx[MAXN],dy[MAXN];
    int dis;
    bool SearchP()
    {
        queue<int> q;
        dis=INF;
        memset(dx,-1,sizeof(dx));
        memset(dy,-1,sizeof(dy));
        for(int i=0;i<uN;++i)
            if(Mx[i]==-1)
            {
                q.push(i);
                dx[i]=0;
            }
        while(!q.empty())
        {
            int u=q.front();q.pop();
            if(dx[u]>dis) break;
            int sz=G[u].size();
            for(int i=0;i<sz;++i)
            {
                int v=G[u][i];
                if(dy[v]==-1)
                {
                    dy[v]=dx[u]+1;
                    if(My[v]==-1) dis=dy[v];
                    else
                    {
                        dx[My[v]]=dy[v]+1;
                        q.push(My[v]);
                    }
                }
            }
        }
        return dis!=INF;
    }
    bool dfs(int u)
    {
        int sz=G[u].size();
        for(int i=0;i<sz;++i)
        {
            int v=G[u][i];
            if(!used[v] && dy[v]==dx[u]+1)
            {
                used[v]=true;
                if(My[v]!=-1 && dy[v]==dis) continue;
                if(My[v]==-1 || dfs(My[v]))
                {
                    My[v]=u;
                    Mx[u]=v;
                    return true;
                }
            }
        }
        return false;
    }
    int MaxMatch()
    {
        int ans=0;
        memset(Mx,-1,sizeof(Mx));
        memset(My,-1,sizeof(My));
        while(SearchP())
        {
            memset(used,false,sizeof(used));
            for(int i=0;i<uN;++i)
                if(Mx[i]==-1 && dfs(i))
                    ++ans;
        }
        return ans;
    }
};
