map<ll, ll> dic;
ll fmod(ll x, ll y, ll p)
{
    ll ans = 1;
    while(y)
    {
        if(y&1) ans = ans*x%p;;
        y>>=1;
        x = x*x%p;
    }
    return ans;
}
ll exbsgs(ll a, ll b, ll p)
{
    if(b == 1LL) return 0;
    ll t, d = 1, k = 0;
    while((t = gcd(a,p)) != 1)
    {
        if(b % t) return -1;
        ++k; b /= t; p /= t; d = d*(a/t)%p;
        if(b == d) return k;
    }
    dic.clear();
    ll m = ceil(sqrt(p)), a_m = fmod(a,m,p), mul = b;
    for(ll j = 1; j <= m; ++j)
    {
        mul = mul *a%p;
        dic[mul] = j;
    }
    for(ll i = 1; i <= m; ++i)
    {
        d = d *a_m%p;
        if(dic[d]) return i*m-dic[d]+k;
    }
    return -1;
}






