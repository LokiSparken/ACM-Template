// 离线Tarjan,时间复杂度：O(n+q)
vector<int> G[maxn];
int par[maxn], vis[maxn], ans[maxn];
vector<PII> query[maxn]; // 存储查询信息
inline void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        G[i].clear(), query[i].clear();
        par[i] = i, vis[i] = 0;
    }
}
inline void add_edge(int u,int v) { G[u].pb(v); }
inline void add_query(int u,int v,int id) { query[u].pb({v, id}); query[v].pb({u, id}); }
void tarjan(int u)
{
    vis[u] = 1;
    for (auto& v : G[u])
    {
        if (vis[v]) continue;
        tarjan(v);
        unite(u, v);
    }
    for (auto& q : query[u])
    {
        int &v = q.X, &id = q.Y;
        if (!vis[v]) continue;
        ans[id] = find(v);
    }
}