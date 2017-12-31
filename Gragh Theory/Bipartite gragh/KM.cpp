/*
 *O(nx*nx*ny)
 *最小权匹配：权值取反，结果取反
 *编号从0开始
 */
struct KM
{
    bool visx[MAXN],visy[MAXN];
    int match[MAXN],lx[MAXN],ly[MAXN];//右点匹配状态，左右点编号
    int G[MAXN][MAXN],slack[MAXN];
    int nx,ny;//两边点数
    bool dfs(int x)
    {
        visx[x]=true;
        for(int y=0;y<ny;++y)
        {
            if(visy[y]) continue;
            int temp=lx[x]+ly[y]-G[x][y];
            if(temp==0)
            {
                visy[y]=true;
                if(match[y]==-1 || dfs(match[y]))
                {
                    match[y]=x;
                    return true;
                }
            }
            else if(slack[y]>temp) slack[y]=temp;
        }
        return false;
    }
    int KM()
    {
        memset(match,-1,sizeof(match));
        memset(ly,0,sizeof(ly));
        for(int i=0;i<nx;++i)
        {
            lx[i]=-INF;
            for(int j=0;j<ny;+j)
                if(G[i][j]>lx[i])
                    lx[i]=G[i][j];
        }
        for(int x=0;x<nx;++x)
        {
            for(int i=0;i<ny;++i) slack[i]=INF;
            while(1)
            {
                memset(visx,false,sizeof(visx));
                memset(visy,false,sizeof(visy));
                if(dfs(x)) break;
                int d=INF;
                for(int i=0;i<ny;++i)
                    if(!visy[i] && d>slack[i])
                        d=slack[i];
                for(int i=0;i<nx;++i)
                    if(visx[i])
                        lx[i]-=d;
                for(int i=0;i<ny;++i)
                {
                    if(visy[i]) ly[i]+=d;
                    else slack[i]-=d;
                }
            }
        }
        int ans=0;
        for(int i=0;i<ny;++i)
            if(match[i]!=-1)
                ans+=G[match[i]][i];
        return ans;
    }
};
