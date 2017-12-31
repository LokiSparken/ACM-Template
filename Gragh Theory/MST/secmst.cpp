struct Edge
{
	int u,v,cost;
	bool use;
	Edge(int u,int v,int c,bool use):u(u),v(v),cost(c),use(use){}
};
struct SecMST
{
    vector<Edge> es;
    int par[MAXN],length[MAXN][MAXN];
    void init(int n)
    {
        for(int i=0;i<=n;++i) par[i]=i;
        memset(length,0,sizeof(length));
        es.clear();
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
    bool same(int A,int B){return Find(A)==Find(B);}
    bool cmp(Edge a,Edge b){return a.cost<b.cost;}
    void update(int u,int v,int cost)
    {
        for(int i=1;i<=N;++i)
            for(int j=1;j<=N;++j)
            {
                if(i!=j && same(a,u) && same(b,v))
                {
                    length[a][b]=length[b][a]=cost;
                }
            }
    }
    int kruskal()
    {
        sort(es.begin(),es.end(),cmp);
        int ans=0;
        for(int i=0;i<es.size();++i)
        {
            Edge &e=es[i];
            int u=e.u,v=e.v,cost=e.cost;
            if(!same(u,v))
            {
                ans+=cost;
                e.use=true;
                update(u,v,cost);//若MST结束DFS遍历树得length效率更高
                uni(u,v);
            }
        }
        return ans;
    }
    int secmst()
    {
        int MST=kruskal();
		int SECMST=INF;
		bool flag=false;
		for(int i=0;i<es.size();++i)
		{
			Edge &e=es[i];
			if(!e.use)
			{
			    //枚举非MST的边(u,v)，加入MST形成环
			    //则SECMST=MST+该边w-所成环中uv间最长边
				SECMST=min(SECMST,MST+e.cost-length[e.u][e.v]);
				if(SECMST==MST)
				{
					flag=true;
					break;
				}
			}
		}
		return SECMST;
    }
};
