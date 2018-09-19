const int maxn = 1e5+5;
const ll mod = 1e9+7;
ll fmod(ll x,ll y, ll M){ll res=1;while(y){if(y&1)res=res*x%M;y>>=1;x=x*x%M;}return res;}
void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b){
        x=1;y=0;d=a;}
    else{
        exgcd(b,a%b,d,y,x);
        y-=a/b*x;}
}
ll inv(ll a,ll M)
{
    if(!a)return 0LL;
    ll d,x = 0LL,y = 0LL;
    exgcd(a,M,d,x,y);
    x = ((x%M) + M)%M;
    if(!x)x += M;
    return x;
}
ll mul(ll n, ll pi, ll pk)
{
    if(!n)return 1LL;
    ll ans = 1LL;
    if(n/pk)
    {
        for(ll i = 2; i <= pk; ++i)
            if(i%pi)ans = ans*i%pk;
        ans = fmod(ans, n/pk, pk);
    }
    for(ll i = 2; i <= n%pk; ++i)
        if(i%pi)ans = ans*i%pk;
    return ans * mul(n/pi,pi,pk)%pk;
}
ll C(ll a, ll b, ll M, ll pi, ll pk)
{
    if(b > a)return 0LL;
    ll x = mul(a,pi,pk),y = mul(b,pi,pk),z = mul(a - b,pi,pk);
    ll cnt = 0LL,ans;
    for(ll i = a; i; i /= pi)cnt += i/pi;
    for(ll i = b; i; i /= pi)cnt -= i/pi;
    for(ll i = a - b; i; i /= pi)cnt -= i/pi;

    ans = x * inv(y,pk)%pk * inv(z,pk)%pk *fmod(pi,cnt,pk)%pk;
    return ans * (M/pk)%M * inv(M/pk, pk)%M;
}
ll ex_lucas(ll a, ll b, ll M)
{
    ll ans = 0;
    for(ll x = M,i = 2; i <= M; ++i)
        if(x%i == 0)
        {
           ll pk = 1LL;
           while(x%i == 0)pk *= i,x /= i;
           ans = (ans + C(a,b,M,i,pk))%M;
        }
        return ans;
}
int main()
{
   ll a,b,m;
   while(cin>>a>>b>>m)
    cout<<ex_lucas(a,b,m)<<endl;
}
