#define lson rt<<1
#define rson rt<<1|1
#define Lson l,mid,lson
#define Rson mid+1,r,rson
int sum[maxn<<2],lz[maxn<<2];
// 注意四倍空间，延迟更新标记的意义，^=1还是用作其它用处
void pushUp(int rt) { sum[rt]=sum[lson]+sum[rson]; }
void build(int l,int r,int rt)
{
    lz[rt]=0;// 延迟更新标记初始化
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return ;
    }
    int mid=(l+r)>>1;
    build(Lson);
    build(Rson);
    pushUp(rt);
}
void update_point(int p,int val,int l,int r,int rt)
{
    if(r==l)
    {
        sum[rt]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid) update(p,val,Lson);
    else update(p,val,Rson);
    pushUp(rt);
}
void pushDown(int rt,int len)
{
    if(lz[rt]==0) return ;
    sum[lson]=lz[rt]*(len-(len>>1));
    sum[rson]=lz[rt]*(len>>1);
    lz[lson]=lz[rson]=lz[rt];
    lz[rt]=0;
}
void update_range(int L,int R,int val,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        lz[rt]=val;
        sum[rt]=val*(r-l+1);//注意所做操作
        return ;
    }
    pushDown(rt,r-l+1);
    int mid=(l+r)>>1;
    if(L<=mid) update(L,R,val,Lson);
    if(mid<R) update(L,R,val,Rson);
    pushUp(rt);
}
int query_range(int L,int R,int l,int r,int rt)
{
    if(L<=l && r<=R) return sum[rt];
    pushDown(rt,r-l+1);
    int mid=(l+r)>>1;
    int s=0;
    if(L<=mid) s+=query(L,R,Lson);
    if(mid<r) s+=query(L,R,Rson);
    return s;
}
