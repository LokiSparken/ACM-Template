struct HLD
{
    vector<int> G[MAXN];
    // 对i：sz以i为根子树大小，dep深度，par父亲，son重儿子，top所在链顶，id入栈序([题目编号]=树链编号)
    int sz[MAXN],dep[MAXN],par[MAXN],son[MAXN],top[MAXN],id[MAXN];
    /* 题目相关信息自己设，###特别注意输入编号与dfs序之间的转换。视情况看要不要reflect[]（[树链编号]=题目编号）### */
    int n,clk;
    void init(int n)
    {
        for(int i=0;i<=n;++i) G[i].clear();
        memset(son,0,sizeof(son));// 如果某结点没有儿子会被之前的数据影响
        this->n=n,clk=0;
    }
    void addedge(int u,int v) { G[u].push_back(v);G[v].push_back(u); }
    void getson(int u,int pre)// 标记深度、父亲、子树大小和重儿子，调用根getson(1,0);
    {
        dep[u]=dep[pre]+1,par[u]=pre,sz[u]=1;
        int fat=0;
        for(auto &v:G[u])
        {
            if(v==pre) continue;
            getson(v,u);
            sz[u]+=sz[v];
            if(sz[v]>fat) fat=sz[v],son[u]=v;
        }
    }
    void dfs(int u,int up)// 标记链顶、入栈序，dfs(1,1);
    {
        top[u]=up,id[u]=++clk,reflect[clk]=u;
        if(son[u]==0) return ;// 已经到达叶子
        dfs(son[u],up);// 每次先走重儿子，重儿子同样在该重链上，链顶相同
        for(auto &v:G[u])// 其它轻儿子的链顶为其本身
            if(v!=son[u] && v!=par[u]) dfs(v,v);
    }

    // 数据结构相关操作，一般线段树或树状数组（维护一段连续区间）
    // 注意：更新和查找操作要用对应的dfs序号id[pos]，可另外写个接口用于在外面调用，和DS分开
    // 接口里面二次调用一定要id[pos]啊啊啊啊啊啊啊啊猪！！！

    int query(int u,int v)
    {
        int ans=0;
        while(top[u]!=top[v])// 先努力跳到同一根链上
        {
            if(dep[top[u]]<dep[top[v]]) swap(u,v);// 让链顶深的往上跳
            // 因为同一根链上是一段连续区间，所以可以直接调维护的数据结构的查询操作了
            ans=max(ans,dsquery(id[top[u]],id[u],1,n,1));// 查要上跳的点所在链的信息
            u=par[top[u]];// 然后跳出这条链，上跳到该链链顶的父亲
        }
        // 此时u,v已经在同一条链上，又可以直接调用维护信息的数据结构的查询操作了qaq
        if(dep[u]>dep[v]) swap(u,v);// 记深度小的点为u（令其dfs入栈序小）
        //此时的u应该是原来u,v的LCA了，因此注意若边权下放点权要去掉LCA
        ans=max(ans,dsquery(id[u],id[v],1,n,1));// 即应变为dsqmax(id[son[u]],id[v])
        return ans;
    }
};