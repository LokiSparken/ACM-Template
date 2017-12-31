typedef pair<int,int> P;
struct Dijkstra
{
    vector<P> G[MAXN];
    int d[MAXN],d2[MAXN];
    void init(int N)
    {
        for(int i=0;i<=N;++i) G[i].clear();
        memset(d,0x3f,sizeof(d));
        memset(d2,0x3f,sizeof(d2));
    }
    void addEdge(int u,int v,int cost)
    {
        G[u].push_back(make_pair(cost,v));
    }
    void dij(int s)
    {
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
//另一种做法：正反跑最短路，枚举每边是否在最短路，非则记此时路长
