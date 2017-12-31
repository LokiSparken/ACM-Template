//poj2396
struct Edge
{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
int low[MAXN][MAXN],up[MAXN][MAXN];
int rowsum[MAXN],colsum[MAXN];
int in[MAXN],out[MAXN];
int n,m,source;
struct ISAP
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool vis[MAXN];
	int d[MAXN],cur[MAXN];
	int p[MAXN],num[MAXN];

	void init(int n)
	{
		this->n=n;
		for(int i=0;i<n;++i) G[i].clear();
		edges.clear();
		memset(d,0x3f,sizeof(d));
	}

	void addedge(int from,int to,int cap)
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

	int Maxflow(int s,int t)
	{
		this->s=s;this->t=t;
		int flow=0;
		bfs();
		if(d[s]>=n) return 0;
		memset(num,0,sizeof(num));
		for(int i=0;i<n;++i)
			if(d[i]<INF) ++num[d[i]];
		int u=s;
		memset(cur,0,sizeof(cur));
		while(d[s]<n)
		{
			if(u==t)
			{
				flow+=Augment();
				u=s;
			}
			int ok=0;
			for(int i=cur[u];i<G[u].size();++i)
			{
				Edge &e=edges[G[u][i]];
				if(e.cap>e.flow && d[u]==d[e.to]+1)
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

	bool build(int m,int n,int s,int t)
	{
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
				if(low[i][j]<=up[i][j])
					addedge(i,j+m,up[i][j]-low[i][j]);
				else return false;

		for(int i=1;i<=m;++i)
		{
			addedge(s,i,rowsum[i]-in[i]);
			source+=rowsum[i]-in[i];
		}
		for(int j=1;j<=n;++j)
		{
			addedge(j+m,t,colsum[j]-out[j]);
		}
		return true;
	}

	void print(int m,int n)
	{
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
			{
				Edge &e=edges[(i-1)*n*2+(j-1)*2];
				if(j>1) putchar(' ');
				printf("%d",e.flow+low[i][j]);
				if(j==n) putchar('\n');
			}
	}
}ans;
void init(int m,int n)
{
	source=0;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			low[i][j]=0,up[i][j]=INF;
}
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&m,&n);
		ans.init(MAXN);
		init(m,n);
		int row=0,col=0;
		for(int i=1;i<=m;++i)
		{
			scanf("%d",&rowsum[i]);
			row+=rowsum[i];
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&colsum[i]);
			col+=colsum[i];
		}
		int C;
		scanf("%d",&C);
		while(C--)
		{
			int r,c,val;
			char ope[5];
			scanf("%d%d%s%d",&r,&c,ope,&val);
			int rstart=r,rend=r,cstart=c,cend=c;
			if(c==0) cstart=1,cend=n;
			if(r==0) rstart=1,rend=m;
			for(int i=rstart;i<=rend;++i)
				for(int j=cstart;j<=cend;++j)
				{
					if(ope[0]=='=')
						low[i][j]=up[i][j]=val;
					else if(ope[0]=='>')
						low[i][j]=max(low[i][j],val+1);
					else if(ope[0]=='<')
						up[i][j]=min(up[i][j],val-1);
				}
		}
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(int i=1;i<=m;++i)
			for(int j=1;j<=n;++j)
				in[i]+=low[i][j];
		for(int j=1;j<=n;++j)
			for(int i=1;i<=m;++i)
				out[j]+=low[i][j];
		int S=0,T=m+n+1;
		bool flag=false;
		if(row!=col) flag=true;
		if(!flag && !ans.build(m,n,S,T)) flag=true;
		int flow=ans.Maxflow(S,T);
		if(!flag && flow!=source) flag=true;
		if(flag) printf("IMPOSSIBLE\n");
		else ans.print(m,n);
		printf("\n");
	}
	return 0;
}
