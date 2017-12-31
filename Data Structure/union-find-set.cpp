int par[MAXN];
void init(int N)
{
    for(int i=0;i<=N;++i) par[i]=i;
}
int find(int x)
{
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void uni(int A,int B)
{
    int x=find(A),y=find(B);
    if(x==y) return ;
    par[x]=y;
}
bool same(int A,int B)
{
    return find(A)==find(B);
}
//按秩合并
void unite(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y) return ;
    if(rank[x]<rank[y])
        parent[x]=y;  // 从rank小的向rank大的连边
    else
    {
        parent[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
}
//非递归路径压缩（避免栈溢出RE）
int find(int x)
{
    int k, j, r;
    r = x;
    while(r != parent[r])     //查找跟节点
        r = parent[r];        //找到跟节点，用r记录下
    k = x;
    while(k != r)             //非递归路径压缩操作
    {
        j = parent[k];        //用j暂存parent[k]的父节点
        parent[k] = r;        //parent[x]指向跟节点
        k = j;                //k移到父节点
    }
    return r;                 //返回根节点的值
}
