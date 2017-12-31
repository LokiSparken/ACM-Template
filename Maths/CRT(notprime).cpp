const int maxn=1e5+5;
int c[maxn],r[maxn];
int n;
//模线性同余方程组（CRT非素数）
//两两方程结合法
//r[i]=x%chu[i],r[i]存余数,chu[i]存除数
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
         int c1=c[1],r1=r[1];
         //a1,r1为合并项
         for(int i=2;i<=n;i++)
         {
             int c2=c[i],r2=r[i];
             //a2,r2为当前项
             int d,x,y,p=r2-r1;

             exgcd(c1,c2,d,x,y);

             if(p%d) return -1;

             int z=c2/d;
             x=(x*(p/d)%z+z)%z;
             r1=x*c1+r1;
             c1=c1*(c2/d);
             r1=(r1%c1+c1)%c1;
         }
         return (r1%c1+c1)%c1;
}
//队长后面是我测试的
int main()
{
    cin>>n;

         for(int i=1;i<=n;i++)
        {
            cin>>c[i]>>r[i];
        }
        cout<<Chinese_Remainder()<<endl;
}