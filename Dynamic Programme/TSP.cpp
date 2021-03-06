void TSP()
{
    memset(dp,0x3f,sizeof(dp));
    for(int i=0;i<m;++i) dp[1<<i][i]=0;
    for(int i=1;i<(1<<m);++i)// 枚举状态：经过哪些点
        for(int j=0;j<m;++j)// 经过这些点时到达的最后一个点
            if(dp[i][j]!=inf)// 这个状态是合法的
/** 我觉得其实i里存在j判断合法不太对？存在j也有可能到不了j状态是inf？
但i&(1<<j)也可以过，是因为取小操作避免了从inf转移过去？
dp[i][j]!=inf这个判断比i&(1<<j)快了15ms，可能的确存在符合后者但inf的情况。
好吧，再交次没区别了，甚至更慢了点，可能是看机器心情吧orz**/
                for(int k=0;k<m;++k)// 枚举新走到的点，那么它一定是新的终点
                    if(((i&(1<<k))==0) && cost[j][k]!=inf)
                        dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],dp[i][j]+cost[j][k]);
/** 注意如果i中已有k点，那么如果发生转移，有可能发生：
经过i这个集合，终点在x，但是又转移到了y，也就是这个状态同时有两个终点了，而这个转移又修改了状态，就GG了！！！
**/
}