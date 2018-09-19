/* 求一个数的phi，时间复杂度sqrt(n) */
inline ll Phi(ll num)
{
    int ans = num;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
        {
            ans -= ans / i;
            while (num % i == 0)
                num /= i;
        }
    if (num > 1)
        ans -= ans / num;
    return phi[num] = ans;
}

/* 
 * 线性筛O(n)得1e7内所有数的欧拉函数phi[]、素数表prime[]、素数个数tot
 * 不要phi时可以把所有关于phi的表达式去掉（别去break），传入的n为函数定义域上界。
 */
bool vis[maxn];
int tot, phi[maxn], prime[maxn];
void CalPhi(int n)
{
    memset(vis, 0, sizeof(vis));
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i < n; i++)
    {
        if (!vis[i]) prime[tot++] = i, phi[i] = i - 1;
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > n) break;
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}