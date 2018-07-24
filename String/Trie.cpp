/* 
 * 插入和查询时间复杂度：O(length)
 * 空间换时间，利用“公共前缀”降低查询时间的开销。
 * 使用时注意点：需要维护的信息。
 */
struct Trie
{
    int ch[MAXN][26];
    int val[MAXN];
    int id,rt;
    void init() { id=0,rt=newNode(); }
    int idx(char c) { return c-'a'; }
    int newNode()
    {
        memset(ch[id],-1,sizeof(ch[id]));
        val[id]=0;
        return id++;
    }
    void insert(string &s)
    {
        int u=rt;
        for(auto &it:s)
        {
            int c=idx(it);
            if(ch[u][c]==-1) ch[u][c]=newNode();
            u=ch[u][c];
        }
        val[u]=1;
    }
    // query is similar to the insert function
}t;
