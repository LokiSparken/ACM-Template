struct Trie{
    int ch[maxnode][sigma_size];
    int val[maxnode];
    int sz;
    void clear()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(val,0,sizeof(val));
    }
    int idx(char c)
    {
        return c-'a';
    }
    void insert(const char*s)
    {
        int u=0,n=strlen(s);
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(sz));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
            val[u]++;
        }
    }
    int search(const char *s)
    {
        int u=0,n=strlen(s);
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            if(!ch[u][c])
            {
                return 0;
            }
            u=ch[u][c];
        }
        return val[u];
    }
}ans;
