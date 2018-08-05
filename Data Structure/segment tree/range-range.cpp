int sum[MAXN<<2],seg[MAXN<<2];
void pushUp(int rt) { sum[rt]=sum[lson]+sum[rson]; }
void build(int L,int R,int rt)
{
    seg[rt]=0;
    if(L==R)
    {
        sum[rt]=1;
        return ;
    }
    int mid=(L+R)>>1;
    build(Lson);
    build(Rson);
    pushUp(rt);
}
void pushDown(int rt,int len)
{
    if(seg[rt]==0) return ;
    sum[lson]=seg[rt]*(len-(len>>1));
    sum[rson]=seg[rt]*(len>>1);    
    seg[lson]=seg[rt];
    seg[rson]=seg[rt];
    seg[rt]=0;
}
void update(int l,int r,int val,int L,int R,int rt)
{
    if(l<=L && R<=r)
    {
        seg[rt]=val;
        sum[rt]=val*(R-L+1);            //注意所做操作
        return ;
    }
    pushDown(rt,(R-L+1));
    int mid=(L+R)>>1;
    if(l<=mid) update(l,r,val,Lson);
    if(mid<r) update(l,r,val,Rson);
    pushUp(rt);
}
int query(int l,int r,int L,int R,int rt)
{
    if(l<=L && r<=R) return sum[rt];
    pushDown(rt,R-L+1);
    int mid=(L+R)>>1;
    int s=0;
    if(l<=mid) s+=query(l,r,Lson);
    if(mid<r) s+=query(l,r,Rson);
    return s;
}
