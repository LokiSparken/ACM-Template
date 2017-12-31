int d[maxn][maxn],sum,n,m;
//二维树状数组,n,m分别为下界,右界
//d[maxn][maxn]为信息,sum为前d[x][y]项和,单点更新,矩阵块求和。
//解决矩形图点更新，区域求和等二维问题
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int y,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))//i,x为行方向
        for(int j=y;y<=m;j+=lowbit(j))//j,y为列方向
    {
        d[i][j]+=v;
    }
}
int getsum(int x,int y)
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
    {
        sum+=d[i][j];
    }
    return sum;
}
