int block[MAXN],cnt[MAXN],a[MAXN];
int n,q,Ans,ans[MAXN];
struct Node
{
    int l,r,id;
    bool operator<(const Node &b)const
    {
        if(block[l]==block[b.l]) return (block[l]&1)?(r<b.r):(b.r<r);
        return block[l]<block[b.l];
    }
}ask[MAXN];
inline void add(int pos){}
inline void del(int pos){}
void Mos()
{
    // read data
    int sz=ceil(sqrt(1.0*n));
    for(int i=1;i<=q;++i)
    {
        // read l,r
        ask[i].id=i;
        block[i]=i/sz;
    }
    sort(ask+1,ask+q+1);
    // init assistant space
    int L=1,R=1;Ans=0;add(1);
    for(int i=1;i<=q;++i)
    {
        while(L<ask[i].l) del(L++);
        while(L>ask[i].l) add(--L);
        while(R<ask[i].r) add(++R);
        while(R>ask[i].r) del(R--);
        ans[ask[i].id]=Ans;
    }    
}