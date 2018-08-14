typedef pair<int,int> P;
struct Dijkstra
{
    vector<P> G[maxn];
    int d[maxn],d2[maxn];
    void init(int n) { for(int i=0;i<=n;++i) G[i].clear(); }
    void addEdge(int u,int v,int cost) { G[u].push_back(make_pair(cost,v)); }
    void dij(int s)
    {
        memset(d,0x3f,sizeof(int)*(n+5));
        memset(d2,0x3f,sizeof(int)*(n+5));
        priority_queue<P,vector<P>,greater<P> > q;
        d[s]=0;
        q.push(make_pair(d[s],s));
        while(!q.empty())
        {
            P temp=q.top();q.pop();
            int v=temp.Y;
            if(d2[v]<temp.X) continue;
            for(int i=0;i<G[v].size();++i)
            {
                int u=G[v][i].Y,cost=G[v][i].X;
                int dist=temp.X+cost;
                if(d[u]>dist)//该点当前最短路比新距离大
                {
                    swap(d[u],dist);
                    q.push(P(d[u],u));
                }
                if(d2[u]>dist && d[u]<dist)
                {
                    d2[u]=dist;
                    q.push(P(d2[u],u));
                }
            }
        }
    }
};
// 另：正反最短路，枚举边<u,v,cost>是否在最短路，非则ds[u]+dt[v]+cost可能是次短路
