int par[maxn];
void init(int n) { for(int i=0;i<=n;++i) par[i]=i; }
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
bool same(int A,int B) { return find(A)==find(B); }
// 带权
int find(int x)
{
    if(par[x]==x) return x;
    int temp=par[x];
    par[x]=find(par[x]);
    rk[x]^=rk[temp];
    return par[x];
}
void uni(int A,int B,int type)
{
    int x=find(A),y=find(B);
    if(x==y) return ;

    int relat;
    if(type==1) relat=0;
    else relat=1;

    rk[y]=(rk[A]+relat-rk[B]+2)%2;
    par[y]=x;
}
// 按秩合并
void unite(int x,int y)
{
    x=find(x),y=find(y);
    if(x==y) return ;
    if(rk[x]<rk[y]) par[x]=y;  // 从rk小的向rk大的连边
    else
    {
        par[y]=x;
        if(rk[x]==rk[y]) rk[x]++;
    }
}
//非递归路径压缩（避免栈溢出RE）
int find(int x)
{
    int k, j, r;
    r = x;
    while(r != par[r])     //查找跟节点
        r = par[r];        //找到跟节点，用r记录下
    k = x;
    while(k != r)             //非递归路径压缩操作
    {
        j = par[k];        //用j暂存par[k]的父节点
        par[k] = r;        //par[x]指向跟节点
        k = j;                //k移到父节点
    }
    return r;                 //返回根节点的值
}
