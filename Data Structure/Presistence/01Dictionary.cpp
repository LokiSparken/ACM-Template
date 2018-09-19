// 可持久化01字典树
const int maxn=1e5+5;
int ch[maxn*20][2],cnt[maxn*20],rt[maxn];
int sz,a[maxn];
void inittree()
{
    sz=0,cnt[0]=0;
    memset(ch[0],-1,sizeof(ch[0]));
    memset(cnt,0,sizeof(cnt));
}
// 维护每个点到根这条路径上所有点的权值构成的字典树
int insert(int old,int val)
{
    ++sz;
    int entry=sz,dad=sz;// 版本入口，父亲结点（旧版本继承来的）
    ch[sz][0]=ch[old][0],ch[sz][1]=ch[old][1];
    cnt[sz]=0;
    // cnt[sz]=cnt[old];
    for(int i=16;i>=0;--i)
    {
        int bit=(val>>i)&1;
        int newnode=++sz;
        // 创建新结点，先继承旧版本的对应结点过来（此时父亲还是旧版的没有更改过）
        // 继承的时候一定要注意继承对啊你是猪吗啊啊啊啊啊啊啊啊！！！！！！！！
        ch[newnode][0]=ch[ch[dad][bit]][0],ch[newnode][1]=ch[ch[dad][bit]][1];
        cnt[newnode]=cnt[ch[dad][bit]];
        ++cnt[newnode];// 更新这个结点记录的个数
        // printf("id=%d bit=%d cnt=%d\n",newnode,bit,cnt[newnode]);
        ch[dad][bit]=newnode;// 把本版本的父亲连到这个新结点
        dad=newnode;// 为向下更新做准备
    }
    return entry;
}
// 求u->v路径上除了lca的所有点权中和z异或值最大的结果值
int query(int u,int v,int lca,int z)
{
    int ans=0;
    for(int i=16;i>=0;--i)
    {
        int bit=(z>>i)&1;
        int num=cnt[ch[u][bit^1]]+cnt[ch[v][bit^1]]-2*cnt[ch[lca][bit^1]];
        // printf("digit=%d bit=%d num=%d+%d-%d=%d\n",i,bit,cnt[ch[u][bit^1]],cnt[ch[v][bit^1]],2*cnt[ch[lca][bit^1]],num);
        if(num>0) ans|=(1<<i), bit^=1;
        // 这一位有跟它相反的就往那走（bit^=1），否则只能走另一个方向
        u=ch[u][bit],v=ch[v][bit],lca=ch[lca][bit];
    }
    // printf("query ans=%d\n",ans);
    return ans;
}
void build(int u)
{
    rt[u]=insert(rt[par[u]],a[u]);
    for(auto &v:G[u])
        if(v!=par[u]) build(v);
}
