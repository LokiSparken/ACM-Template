struct AC
{
    int ch[maxnode][sigma_size];
    int val[maxnode],f[maxnode],last[maxnode];
    int sz;
    void init()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(val,0,sizeof(val));
        memset(f,0,sizeof(f));
        memset(last,0,sizeof(last));
    }
    int idx(char c){return c-'A';}
    void insert(char *s,int id)
    {
        int n=strlen(s),u=0;
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=id;
    }
    void getfail(int *f)
    {
        queue<int> q;
        f[0]=0;
        for(int c=0;c<sigma_size;c++)
        {
            int u=ch[0][c];
            if(u)
            {
                f[u]=0;
                q.push(u);
                last[u]=0;
            }
        }
        while(!q.empty())
        {
            int r=q.front();q.pop();
            for(int c=0;c<sigma_size;c++)
            {
                int u=ch[r][c];
                if(!u)
                {
                    ch[r][c]=ch[f[r]][c];
                    continue;
                }
                q.push(u);
                int v=f[r];
                while(v &&!ch[v][c]) v=f[v];
                f[u]=ch[v][c];
                last[u]= val[f[u]]? f[u]:last[f[u]];
            }
        }
    }
    void find(char *t,int *f)
    {
        int n=strlen(t);
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(t[i]>'Z'||t[i]<'A')
            {
                j=0;
                continue;
            }
            int c=idx(t[i]);
            j=ch[j][c];
            if(val[j]) vis[val[j]]++;
            if(last[j]) bfind(last[j]);
        }
    }
    void bfind(int j)
    {
        if(j)
        {
            vis[j]++;
            bfind(last[j]);
        }
    }
};
