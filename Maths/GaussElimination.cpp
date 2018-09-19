const double eps=1e-8;
const int maxn=1e3+5;
typedef double Matrix[maxn][maxn];
//保证可逆
void gauss_emilination(Matrix A,int n)
{
    //求解的增广矩阵，最后的A[i][n]是弟i个未知数的值
    for(int i=0;i<n;i++)
    {
        //选一行r并和i行交换
        int r=i;
        for(int j=i+1;j<n;j++)
            if( fabs(A[j][i]) > fabs(A[r][i]) )
                r=j;
        if(r!=i)
            for(int j=0;j<=n;j++)swap(A[r][j],A[i][j]);
        //与i+1~n行消元
        for(int k=i+1;k<n;k++)
        {
            double f=A[k][i]/A[i][i];
            for(int j=i;j<=n;j++)A[k][j]-=f*A[i][j];
        }
    }
    //回代求值
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
            A[i][n]-=A[j][n]*A[i][j];
        A[i][n]/=A[i][i];
    }
}
