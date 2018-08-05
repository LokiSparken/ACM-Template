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
    while((1<<(k+1))<=r-l+1) k++;
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}

const int maxn=100;
int dp[maxn][maxn][9][9],s[maxn][maxn];
int n,m;
//区域最值问题
void RMQ_init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           dp[i][j][0][0]=s[i][j];

    for(int j=0;(1<<j)<=n;j++)
        for(int i=0;(1<<i)<=m;i++)
            if(i+j)
                for(int jj=0;jj+(1<<j)-1<n;jj++)
                    for(int ii=1;ii+(1<<i)-1<=m;ii++)
                        if(j==0)
                            dp[jj][ii][j][i]=min(dp[jj][ii][j][i-1],
                                                 dp[jj][ii+(1<<(i-1))][j][i-1]);
                        else
                            dp[jj][ii][j][i]=min(dp[jj][ii][j-1][i],
                                                 dp[jj+(1<<(j-1))][ii][j-1][i]);
}
int RMQ(int x1,int y1,int x2,int y2)
{
    int a=0,b=0;
    while((1<<(a+1))<=x2-x1+1)a++;
    while((1<<(b+1))<=y2-y1+1)b++;
    x2=x2-(1<<a)+1;
    y2=y2-(1<<a)+1;
    return min(min(dp[x1][y1][a][b],dp[x1][y2][a][b]),
               min(dp[x2][y1][a][b],dp[x2][y2][a][b]));
}