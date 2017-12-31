struct Floyd
{
    double d[MAXN][MAXN];
    void floyd(int N)
    {
        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                {
                    if(d[i][k] && d[k][j] && d[i][j]<d[i][k]*d[k][j])
                        d[i][j]=d[i][k]*d[k][j];
                }
    }
};
