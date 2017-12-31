#define lson rt<<1
#define rson rt<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int sum[MAXN<<2];
void pushUp(int rt)
{
    sum[rt]=sum[lson]+sum[rson];
}
void build(int L,int R,int rt)
{
    if(L==R)
    {
        scanf("%d",&sum[rt]);
        return ;
    }
    int mid=(L+R)>>1;
    build(Lson);
    build(Rson);
    pushUp(rt);
}
void update(int p,int val,int L,int R,int rt)
{
    if(L==R)
    {
        sum[rt]+=val;
        return;
    }
    int mid=(L+R)>>1;
    if(p<=mid) update(p,val,Lson);
    else update(p,val,Rson);
    pushUp(rt);
}
int query(int l,int r,int L,int R,int rt)
{
    if(L>=l && R<=r) return sum[rt];
    int mid=(L+R)>>1,sum=0;
    if(l<=mid) sum+=query(l,r,Lson);
    if(r>mid) sum+=query(l,r,Rson);
    return sum;
}
