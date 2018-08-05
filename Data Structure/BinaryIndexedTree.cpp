int bit[maxn],n,m;// n下界，m右界，bit信息，getsum求前缀和。
inline int lowbit(int x) { return x&(-x); }
// 一维，区间段求和[1]~[pos]解决逆序对、连线交叉点等问题。非线性排列可通过dfs序、树链剖分等转化为线性排列。
void add(int pos,int val)
{
    for(int i=pos;i<=n;i+=lowbit(i))
        bit[i]+=val;
}
int getsum(int pos)
{
    int sum=0;
    for(int i=pos;i>0;i-=lowbit(i))
        sum+=bit[i];
    return sum;
}
// 二维，矩阵块求和[1,1]~[x,y]。解决矩形图点更新，区域求和等二维问题。
void add(int x,int y,int val)
{
    for(int i=x;i<=n;i+=lowbit(i))//i,x为行方向
        for(int j=y;y<=m;j+=lowbit(j))//j,y为列方向
            bit[i][j]+=val;
}
int getsum(int x,int y)
{
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            sum+=bit[i][j];
    return sum;
}