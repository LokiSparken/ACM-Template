/*
 *二分图最大权完美匹配，时间复杂度O(nx*nx*ny)
 *最小权匹配：权值取反，结果取反
 */
struct KM
{
    int nx,ny;// 左右两边点数，两边编号都从0开始
    int G[MAXN][MAXN];// 非完全图全覆盖应初始化为-inf
    int linker[MAXN],lx[MAXN],ly[MAXN];
    // 最终左边的i点匹配到右边的点linker[i],lx[i]左边的i点连到右边的最大权边
    int slack[MAXN];
    bool visx[MAXN],visy[MAXN];
    bool dfs(int x)
    {
        visx[x]=true;
        for(int y=0;y<ny;++y)
        {
            if(visy[y]) continue;
            int tmp=lx[x]+ly[y]-G[x][y];
            if(tmp==0)
            {
                visy[y]=true;
                if(linker[y]==-1 || dfs(linker[y]))
                {
                    linker[y]=x;
                    return true;
                }
            }
            else if(slack[y]>tmp) slack[y]=tmp;
        }
        return false;
    }
    int km()
    {
        memset(linker, - 1,sizeof(linker));
        memset(ly,0,sizeof(ly));
        for(int i = 0; i < nx; i++)
        {
            lx[i] = - inf;
            for(int j = 0; j < ny; j++)
                if(G[i][j] > lx[i])
                    lx[i] = G[i][j];
        }
        for(int x = 0; x < nx; x++)
        {
            for(int i = 0; i < ny; i++) slack[i] = inf;
            while(true)
            {
                memset(visx,false,sizeof(visx));
                memset(visy,false,sizeof(visy));
                if(dfs(x)) break;
                int d = inf;
                for(int i = 0; i < ny; i++)
                    if(!visy[i] && d > slack[i])
                        d = slack[i];
                for(int i = 0; i < nx; i++)
                    if(visx[i]) lx[i] -= d;
                for(int i = 0; i < ny; i++)
                {
                    if(visy[i]) ly[i] += d;
                    else slack[i] -= d;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < ny; i++)
            if(linker[i] != - 1)
                ans += G[linker[i]][i];
        return ans;
    }
};
