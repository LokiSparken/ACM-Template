void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b) x=1,y=0,d=a;
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=a/b*x;
    }
}
ll inv(ll a,ll n)
{
    ll d,x,y;
    exgcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}
