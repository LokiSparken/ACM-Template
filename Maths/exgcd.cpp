//d最小公倍数,解方程ax+by=gcd(a,b)
//对于方程ax+by=c;要求c能被gcd(a,b)整除
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








