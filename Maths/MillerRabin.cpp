const int T=8;
ll random(ll n) { return (ll)((double)rand()/RAND_MAX*n+0.5); }
ll fmod(ll a,ll b,ll c)//a^b%c;
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}
bool Witness(ll a,ll b)//a^b;
{
    ll m=b-1; int j=0;
    while(!(m&1)) //分解b-1=m*2^j;
        j++, m>>=1;
    ll x=fmod(a,m,b);
    if( x==1 || x==b-1 ) return true;
    while(j--)     //二次探测
    {
        x=x*x%b;
        if(x==b-1) return true;
    }
    return false;
}
bool miller_rabin(ll x)
{
    if(x<2)return false;
    if(x==2)return true;
    if(!(x&1))return false;
    for(int i=1;i<=T;i++)
    {
        ll a=random(x-2)+1;
        if(!Witness(a,x))
            return false;
    }
    return true;
}
int main()
{
    ll x;
    while(cin>>x)
    {
        if(miller_rabin(x)) cout<<"素数"<<endl;
        else cout<<"合数"<<endl;
    }
}







