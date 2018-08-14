// 欧拉序列+ST表，时间复杂度O(2nlog(2n)+q)
vector<int> G[maxn];
vector<int> seq;// 欧拉序列（但叶子处只放了一个）
int dep[maxn], in[maxn];// 深度和各点进栈时间(从0开始)
pair<int,int> dp[21][maxn << 1];// dp[log(maxn)][maxn<<1],.X为深度，.Y为位置
void init(int n)
{
    for (int i = 0; i <= n; i++) G[i].clear();
    seq.clear();
}
void addedge(int u,int v) { G[u].emplace_back(v); G[v].emplace_back(u); }
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    in[u] = seq.size();// 进栈时间
    seq.push_back(u);
    for (auto &v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u);
        seq.push_back(u);
    }
    // 出栈时间seq.size()+1;
}
void initrmq()
{
    int n = seq.size();
    for (int i = 0; i < n; i++) dp[0][i] = {in[seq[i]], seq[i]};
    for (int i = 1; (1 << i) <= n; i++)
        for (int j = 0; j + (1 << i) - 1 < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
}
int lca(int u, int v)
{
    int l = in[u], r = in[v];
    if (l > r) swap(l, r);
    int k = 31 - __builtin_clz(r - l + 1);
    return min(dp[k][l], dp[k][r - (1 << k) + 1]).Y;
}