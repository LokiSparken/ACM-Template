struct Edge
{
    int u,v,d;
    Edge(int from,int to,int cost):u(from),v(to),d(cost){}
    bool operator < (const Edge &a)const
    {
        return d<a.d;
    }
};
struct Kruskal
{
    vector<Edge> edges;
    int par[MAXN];
    int n;
    void init(int n)
    {
        this->n=n;
        edges.clear();
        for(int i=1;i<=n;++i) par[i]=i;
    }
    void add_edge(int u,int v,int d)
    {
        edges.push_back(Edge(u,v,d));
        edges.push_back(Edge(v,u,d));
    }
    int Find(int x)
    {
        if(par[x]==x) return x;
        return par[x]=Find(par[x]);
    }
    void uni(int A,int B)
    {
        int x=Find(A),y=Find(B);
        if(x==y) return ;
        par[x]=y;
    }
    bool same(int A,int B)
    {
        return Find(A)==Find(B);
    }
    int kruskal()
    {
        sort(edges.begin(),edges.end());
        int ans=0;
        for(int i=0;i<edges.size();++i)
        {
            Edge &e=edges[i];
            if(!same(e.v,e.u))
            {
                ans+=e.d;
                uni(e.v,e.u);
            }
        }
        return ans;
    }
};
