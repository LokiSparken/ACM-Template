const ll mod = 1e9+7;
ll fac[100005];
ll fmod(ll x, ll y){ll res = 1;while(y){if(y&1)res=res*x%mod;y>>=1;x=x*x%mod;}return res;}
ll facinit()
{
    fac[0] = fac[1] = 1;
    for(ll i = 2; i <= 100000; ++i)
        fac[i] = fac[i - 1]*i%mod;
}
ll C(ll a, ll b)
{
    if(b > a)return 0;
    return fac[a]*fmod(fac[b]*fac[a-b], mod - 2LL)%mod;
}
ll lucas(ll a,ll b)
{
    if(!b)return 1;
    return C(a%mod, b%mod)*lucas(a/mod, b/mod)%mod;
}
int main()
{
    ll x,y; facinit();
    while(cin>>x>>y)
        cout<<lucas(x,y)<<endl;
}
