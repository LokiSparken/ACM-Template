int d[maxn],sum,n;
//树状数组,n为上界
//d[maxn]为信息,sum为前d[x]项和,单点更新,区间段求和。
//解决逆序对,连线交叉点问题等普通一维问题
//可将非线性排列通过如dfs序转化为线性排列
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        d[i]+=v;
    }
}
int getsum(int x)
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        sum+=d[i];
    }
    return sum;
}













