int dp[maxn];
void zeropack(int c,int v)
{
    for(int i=m;i>=c;i--)
        dp[i]=max(dp[i],dp[i-c]+v);
}
void completepack(int c,int v)
{
    for(int i=c;i<=m;i++)
        dp[i]=max(dp[i],dp[i-c]+v);
}
void multipack(int c,int v,int shu)
{
    if(shu*c>=m)
    {
        completepack(c,v);
        return;
    }
    int k=1;
    while(k<shu)
    {
        zeropack(k*c,k*v);
        shu-=k;
        k*2;
    }
    zeropack(shu*c,shu*v);
}
