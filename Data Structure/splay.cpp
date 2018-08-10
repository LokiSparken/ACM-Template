#define aim ch[ch[rt][1]][0]
// 维护序列的splay，splay上编号为序列下标
struct Splay 
{
    int val[maxn],mx[maxn],lz[maxn],rev[maxn],sz[maxn],ch[maxn][2];
    // 结点值，最大值，标记区间加、翻转，子树大小，左右子结点编号
    int par[maxn],rt;// 各结点父亲编号，splay树的根结点编号
    void newNode(int id,int v)
    {
        val[id]=mx[id]=v,sz[id]=1;
        lz[id]=rev[id]=ch[id][0]=ch[id][1]=0;
    }
    void init(int n)
    {
        newNode(0,-inf),newNode(1,-inf),newNode(n+2,-inf);
        for(int i=2;i<=n+1;++i) newNode(i,0);
        rt=build(1,n+2),par[rt]=0;
        par[0]=0,sz[0]=0,ch[0][1]=rt;
    }

    void pushup(int pos)
    {
        mx[pos]=val[pos],sz[pos]=1;
        int &l=ch[pos][0], &r=ch[pos][1];
        if(l) mx[pos]=max(mx[pos],mx[l]),sz[pos]+=sz[l];
        if(r) mx[pos]=max(mx[pos],mx[r]),sz[pos]+=sz[r];
    }

    int build(int l,int r)
    {
        if(l>r) return 0;
        if(l==r) return l;
        int mid=(l+r)>>1,ls,rs;
        ch[mid][0]=ls=build(l,mid-1);
        ch[mid][1]=rs=build(mid+1,r);
        par[ls]=par[rs]=mid;
        pushup(mid);
        return mid;
    }

    void pushdown(int pos)
    {
        if(pos==0) return ;
        int &l=ch[pos][0], &r=ch[pos][1];
        if(lz[pos])
        {
            int &w=lz[pos];
            if(l) val[l]+=w,mx[l]+=w,lz[l]+=w;
            if(r) val[r]+=w,mx[r]+=w,lz[r]+=w;
            w=0;
        }
        if(rev[pos])
        {
            if(l) rev[l]^=1;
            if(r) rev[r]^=1;
            swap(l,r);
            rev[pos]=0;
        }
    }
        
    int find(int index)// 找到序列里index在splay树中对应的编号
    {
        int u=rt;
        pushdown(u);
        while(sz[ch[u][0]]!=index)
        {
            int lsz=sz[ch[u][0]];
            if(index<lsz) u=ch[u][0];
            else index-=lsz+1,u=ch[u][1];
            pushdown(u);
        }
        return u;
    }
    void rotate(int pos,int type)// type=1右旋,type=0左旋
    {
        int p=par[pos],gp=par[p];// pos的父亲爷爷
        int &son=ch[pos][type];// pos要动的那个子结点
        ch[p][!type]=son,par[son]=p;
        son=p, par[p]=pos;
        ch[gp][ch[gp][1]==p]=pos,par[pos]=gp;
        pushup(p);
    }
    void splay(int pos,int goal)// pos转到goal的右儿子
    {
        if(pos==goal) return ;
        while(par[pos]!=goal)
        {
            int p=par[pos],gp=par[p];
            pushdown(gp),pushdown(p),pushdown(pos);
            int typepos=ch[p][0]==pos,typep=ch[gp][0]==p;
            // 左儿子右旋，右儿子左旋
            if(gp==goal) rotate(pos,typepos);
            else
            {
                if(typepos==typep) rotate(p,typep);
                else rotate(pos,typepos);
                rotate(pos,typep);
            }
        }
        pushup(pos);
        if(goal==0) rt=pos;
    }

    void select(int l,int r)// 此时r+1的左儿子就是操作区间[l,r]
    {
        int u=find(l-1),v=find(r+1);
        splay(u,0),splay(v,u);
    }
    void update(int l,int r,int value)
    {
        select(l,r);
        mx[aim]+=value,val[aim]+=value,lz[aim]+=value;
    }
    void reverse(int l,int r) { select(l,r); rev[aim]^=1; }
    int query(int l,int r) { select(l,r); return mx[aim]; }
}t;