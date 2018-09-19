#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll G = 3;
const int N = 15;
ll wn[N << 2],rev[N << 2];
ll fmod(ll x, ll y, ll z)
{
    ll ans = 1;
    while(y)
    {
        if(y & 1)ans = ans * x % z;
        y >>= 1;
        x = x * x % z;
    }
    return ans;
}
int NTT_init(int n_)
{
    int step = 0; int n = 1;
    for( ; n < n_; n <<= 1)++step;
    for(int i = 1; i < n; ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (step - 1));
    //蝴蝶操作，二进制反转
    int g = fmod(G, (MOD - 1) / n, MOD);
    wn[0] = 1;
    for (int i = 1; i <= n; ++i)
        wn[i] = wn[i - 1] * g % MOD;
    //求出n次单位根
    return n;
}
void NTT(ll a[], int n, int f)
{
    for(int i = 0; i < n; ++i)
        if(i < rev[i])swap(a[i], a[rev[i]]);

    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += (k << 1)) {
            int t = n / (k << 1);
            for(int j = 0; j < k; ++j){
                ll w = f == 1 ? wn[t * j] : wn[n - t * j];
                ll x = a[i + j];
                ll y = a[i + j + k] * w % MOD;
                a[i + j] = (x + y) % MOD;
                a[i + j + k] = (x - y + MOD) % MOD;
            }
        }
    }
    if(f == -1){
      ll ninv = fmod(n, MOD - 2, MOD);
      for(int i = 0; i < n; ++i)
         a[i] = a[i] * ninv % MOD;
    }
}
int main()
{

}






























