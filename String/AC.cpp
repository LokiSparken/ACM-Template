/*
 * maxn为模式串可能的总长，init,insert后别忘了build得fail。
 * 时间复杂度：建树O(n个*len),失配O(n个*len),文本O(长m*失配跳转)
 * 因为失配指针构成失配树，所以失配跳转总数
 */
struct ACchicken
{
    int ch[maxn][26],fail[maxn];
    int val[maxn];
    int sz,rt;
    void init() { sz=0,rt=newNode(); }
    int newNode()
    {
        memset(ch[sz],-1,sizeof(ch[sz]));
        val[sz]=0;
        return sz++;
    }
    inline int idx(char c) { return c-'a'; }
    void insert(const char *s)// 建字典树
    {
        int u=rt;
        for(int i=0;s[i];++i)
        {
            int c=idx(s[i]);
            if(ch[u][c]==-1) ch[u][c]=newNode();
            u=ch[u][c];
        }
        ++val[u];
    }
    void build()// 跑fail同时把各个ch[id][0~size]补全了，所以不该还有走到-1空的情况了
    {
        queue<int> q;
        fail[rt]=rt;
        for(int c=0;c<26;++c)
        {
            if(ch[rt][c]!=-1) fail[ch[rt][c]]=rt,q.push(ch[rt][c]);
            else ch[rt][c]=rt;// 令根不存在的后继回到根重新走
        }
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int c=0;c<26;++c)
            {
                // 后继的失配应看前驱失配的下一个能否匹配，能就连过去，否则看根那有没有能配的
                if(ch[u][c]!=-1) fail[ch[u][c]]=ch[fail[u]][c],q.push(ch[u][c]);
                else ch[u][c]=ch[fail[u]][c];// 没有这种后继的话就从其它能走的模式串后面继续走
            }
        }
    }
    int query(const char *s)
    {
        int u=rt, len=strlen(s);
        int ans=0;
        for(int i=0;s[i];++i)
        {
            int c=idx(s[i]);
            u=ch[u][c];
            int temp=u;
            while(temp!=rt)
            {
                ans+=val[temp];
                val[temp]=0;
                temp=fail[temp];
            }
        }
        return ans;
    }
}t;