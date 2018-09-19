int num[20]; ll dp[20][state];
ll dfs(int pos,/*state*/,int lead/*前导0*/,int limit/*上界*/)
{
    if(pos==-1)return 1;//看情况
    if(!limit&&dp[pos][state]!=-1)return dp[pos][state];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {
        if()...
        else if()...
        ans+=dfs(pos-1,/*状态转移*/,lead&&i==0,limit&&i==a[pos])
        //最后两个基本就这样
    }
    if(!limit&&!lead)dp[pos][state]=ans;
    //比如不能有62那么这里直接记录是不是6  用10表示
    //这样之后的状态则会有重复就可以直接用了
    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,/*状态*/,1,1);
    //刚开始最高位都是有限制并且有前导零的,
    //显然比最高位还要高的一位视为0嘛
}
