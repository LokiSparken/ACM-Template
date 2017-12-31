const int maxn=1e5+5;
int prime[maxn],r[maxn];
//中国剩余定理（除数两两互质）
//r[i]=x%prime[i],r[i]存余数,a[i]存被除数
void exgcd(int a,int b,int &d,int &x,int &y)
{
    if(!b)
    {
        x=1;y=0;d=a;
    }
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=a/b*x;
    }
}
int Chinese_Remainder()
{
    int M=1;
    for(int i=1;i<=n;i++)
        M*=prime[i];//所有除数最小公倍数
    int d,x,y,answer=0;
    for(int i=1;i<=n;i++)
    {
        int m=M/prime[i];
        exgcd(prime[i],m,d,x,y);
        answer=(answer+y*m*r[i])%M;
    }
    return (M+answer%M)%M;

