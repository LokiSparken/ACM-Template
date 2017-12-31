int dp[maxn][maxn],s[maxn];
//储存区间段的最值信息等
void RMQ_init()
{
    //注意编号起始位置
    //依据题进行取值
    for(int i=0;i<n;i++) dp[i][0]=s[i];

    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int RMQ(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1)k++;
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}












