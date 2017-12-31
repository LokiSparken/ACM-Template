struct Edge
{
	int from;
	int d,f;
	Edge(int u,int d,int f):from(u),d(d),f(f){}
	bool operator <(const Edge &a)const     //从大到小排序，避免用反pq
	{
		if(f==a.f) return a.d<d;
		return a.f<f;
	}
};
struct Kpath
{
	vector<pair<int,int> > G[MAXN];
	vector<pair<int,int> > GB[MAXN];
	bool vis[MAXN];
	int h[MAXN];
	int t;
	void init()
	{
		for(int i=0;i<=N;++i)
		{
			G[i].clear();
			GB[i].clear();
		}
		t=0;
		memset(h,0x3f,sizeof(h));
		memset(vis,false,sizeof(vis));
	}
	void addEdge(int u,int v,int cost)
	{
		G[u].push_back(mp(cost,v));
		GB[v].push_back(mp(cost,u));
	}
	void spfa(int s)    //dijstra可能效率更高，另注意题目会不会有负圈
	{
		queue<int> q;
		h[s]=0;
		q.push(s);
		vis[s]=true;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			vis[u]=false;
			for(int i=0;i<GB[u].size();++i)
			{
				int v=GB[u][i].Y,cost=GB[u][i].X;
				if(h[v]>h[u]+cost)
				{
					h[v]=h[u]+cost;
					if(!vis[v])
					{
						q.push(v);
						vis[v]=true;
					}
				}
			}
		}
	}
	int Astar(int S,int T,int K)
	{
		if(S==T) ++K;       //如果S==T，d=0不算一条路
		if(h[S]==INF) return -1;
		priority_queue<Edge> q;
		q.push(Edge(S,0,h[S]));
		while(!q.empty())
		{
			Edge temp=q.top();q.pop();
			int u=temp.from,d=temp.d;
			if(u==T) ++t;
			if(t==K) return d;
			for(int i=0;i<G[u].size();++i)
			{
				int v=G[u][i].Y,cost=G[u][i].X;
				q.push(Edge(v,d+cost,d+cost+h[v]));
			}
		}
		return -1;
	}
};
