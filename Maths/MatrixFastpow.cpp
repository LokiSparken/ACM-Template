const int N;
struct matrix
{
    long long mat[N][N];
};
matrix operator *(matrix a,matrix b)
{
    matrix c;
    memset(c.mat,0,sizeof(c.mat));
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
        {
            if(a.mat[i][k]==0)
                continue;
            for(int j=0;j<N;j++)
            {
                if(b.mat[k][j]==0)
                    continue;
                c.mat[i][j]=(c.mat[i][j]+(a.mat[i][k]*b.mat[k][j])%mod)%mod;
            }
        }
    return c;
}
matrix operator ^(matrix a,int n)
{
    matrix c;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            c.mat[i][j]= (i==j);
    while(n)
    {
        if(n&1)
            c=c*a;
        a=a*a;
        n>>=1;
    }
    return c;
}
