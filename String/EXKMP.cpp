struct exKMP
{
    char t[maxn];
    char p[maxn];
    int f[maxn];
    int extend[maxn];
    void getfail(char *p,int *f)
    {
        int m=strlen(p);
        f[0]=m;
        int i=0;
        while(i<m-1&&p[i]==p[i+1])
            i++;
        f[1]=i;
        int po=1;
        for(i=2;i<m;i++)
        {
            if(f[i-po]+i<po+f[po])
                f[i]=f[i-po];
            else
            {
                int j=po+f[po]-i;
                if(j<0)
                    j=0;
                while((i+j<m)&&p[i+j]==p[j])
                    j++;
                f[i]=j;
                po=i;
            }
        }
    }
    void getextend(char *t,char *p,int *f,int *extend)
    {
        int n=strlen(t);
        int m=strlen(p);
        getfail(p,f);
        int i=0;
        while(t[i]==p[i]&&i<n&&i<m)
            i++;
        extend[0]=i;
        int po=0;
        for(int i=1;i<n;i++)
        {
            if(f[i-po]+i<extend[po]+po)
                extend[i]=f[i-po];
            else
            {
                int j=extend[po]+po-i;
                if(j<0)
                    j=0;
                while(i+j<n&&j<m&&t[i+j]==p[j])
                    j++;
                extend[i]=j;
                po=i;
            }
        }
    }
}ans;
