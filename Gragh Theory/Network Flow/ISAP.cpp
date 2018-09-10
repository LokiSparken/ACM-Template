struct Edge
{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct ISAP
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn],cur[maxn];
	int p[maxn],num[maxn];
	void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;++i) G[i].clear();
		edges.clear();
		memset(d,0x3f,sizeof(d));
	}
	void add_edge(int from,int to,int cap)
	{
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool bfs()
	{
		memset(vis,false,sizeof(vis));
		queue<int> q;
		q.push(t);
		d[t]=0;
		vis[t]=true;
		while(!q.empty())
		{
			int u=q.front();q.pop();
			for(int i=0;i<G[u].size();++i)
			{
				Edge &e=edges[G[u][i]^1];
				if(!vis[e.from] && e.cap>e.flow)
				{
					vis[e.from]=true;
					d[e.from]=d[u]+1;
					q.push(e.from);
				}
			}
		}
		return vis[s];
	}
	int Augment()
	{
		int flow=INF;
		for(int u=t;u!=s;u=edges[p[u]].from)
		{
			Edge &e=edges[p[u]];
			flow=min(flow,e.cap-e.flow);
		}
		for(int u=t;u!=s;u=edges[p[u]].from)
		{
			edges[p[u]].flow+=flow;
			edges[p[u]^1].flow-=flow;
		}
		return flow;
	}
	int Maxflow(int s,int t)// 可以再加第三个参数流量>=UP剪枝直接return
	{
		this->s=s;this->t=t;
		int flow=0;
		bfs();
		if(d[s]>=n) return 0;
		memset(num,0,sizeof(num));
		for(int i=0;i<n;++i)
			if(d[i]<inf) ++num[d[i]];
		int u=s;
		memset(cur,0,sizeof(cur));
		while(d[s]<n)
		{
			if(u==t)
			{
				flow+=Augment();
				// if(flow>=up) return flow;
				u=s;
			}
			int ok=0;
			for(int i=cur[u];i<G[u].size();++i)
			{
				Edge &e=edges[G[u][i]];
				if(e.cap>e.flow && d[u] == d[e.to]+1)
				{
					ok=1;
					p[e.to]=G[u][i];
					cur[u]=i;
					u=e.to;
					break;
				}
			}
			if(!ok)
			{
				int m=n-1;
				for(int i=0;i<G[u].size();++i)
				{
					Edge &e=edges[G[u][i]];
					if(e.cap>e.flow) m=min(m,d[e.to]);
				}
				if(--num[d[u]]==0) break;
				++num[d[u]=m+1];
				cur[u]=0;
				if(u!=s) u=edges[p[u]].from;
			}
		}
		return flow;
	}
};
