struct l_B
{
    ll d[61],b[61]; int cnt = 0;
    void init() { clr(d,0), clr(b,0), cnt = 0; }
    bool insrt(ll val)
    {
        for(int i = 60; i >= 0; i--)
        {
            if(!d[i])
            {
                d[i] = val;
                break;
            }
            val ^= d[i];
        }
        return val > 0;
    }
    ll get_max()
    {
        ll ans = 0;
        for(int i = 60; i >= 0; --i)
            if((ans^d[i] > ans))
                ans ^= d[i];
        return ans;
    }
    ll get_min()
    {
        for(int i = 0; i <= 60; ++i)
            if(d[i]) return d[i];
        return 0;
    }
    void rebuild()
    {
        for(int i = 60; i >= 0; --i)
            for(int j = i - 1; j >= 0; --j)
                if(d[i]&(1LL<<j))d[i] ^= d[j];
        for(int i = 0; i <= 60; ++i)
            if(d[i])b[cnt++] = d[i];
    }
    ll get_kth(ll k)
    {
        ll ans = 0;
        if( k >= (1LL<<cnt) ) return -1;
        for(int i = 60; i >= 0; --i)
            if(k&(1LL<<i))ans ^= b[i];
        return ans;
    }
};
l_B merg(const l_B &x,const l_B &y)
{
    l_B ans = x;
    for(int i = 60; i >= 0; --i)
        if(y.d[i])ans.insrt(y.d[i]);
    return ans;
}
//保持上三角性质的求线性基
void cal()
{
    for(int i = 0; i < n; ++i)
       for(int j = max_size; j >= 0; --j)
            if((a[i] >> j)&1)
            {
                if(b[j]) a[i] ^= b[j];
                else
                {
                    b[j] = a[i];
                    for(int k = j - 1; k >= 0; --k)
                        if(b[k]&&((b[j] >> k)&1)) b[j] ^= b[k];
                    for(int k = j + 1; k <= max_size; ++k)
                        if((b[k] >> j)&1) b[k] ^= b[j];
                }
            }
}















