struct Manacher
{
    char p[maxn];
    char temp[maxn<<1];
    int f[maxn<<1];
    void init(char *p,char *temp)
    {
        int n=strlen(p);
        temp[0]='*';
        for(int i=0;i<=n;i++)
        {
            temp[i*2+1]='#';
            temp[i*2+2]=p[i];
        }
        temp[2*n+2]='\0';
    }
    void getlen(char *p,int *f)
    {
        int mx=0,po=0,ans=0;
        int n=strlen(p);
        f[0]=0;
        for(int i=2;i<n;i++)
        {
            if(mx>i)
                f[i]=min(mx-i,f[2*po-i]);
            else
                f[i]=1;
            while(p[i-f[i]]==p[i+f[i]])
                f[i]++;
            if(f[i]+i>mx)
            {
                po=i;
                mx=f[i]+i;
            }
        }
    }
}ans;
