struct kmp{
    int s[maxN];
    int p[maxM];
    int f[maxM];
    void getfail(int *p,int *f)
    {
        int m=M;
        f[0]=0;
        f[1]=0;
        for(int i=1;i<m;i++)
        {
            int j=f[i];
            while(j&&p[i]!=p[j])
                j=f[j];
            f[i+1]=p[i]==p[j]?j+1:0;
        }
    }
    int find(int *t,int *p,int *f)
    {
        int n=N;
        int m=M;
        getfail(p,f);
        int j=0;
        for(int i=0;i<n;i++)
        {
            while(j&&p[j]!=t[i])
                j=f[j];
            if(p[j]==t[i])
                j++;
            if(j==m)
                return i-m+2;
        }
        return -1;
    }
}ans;
