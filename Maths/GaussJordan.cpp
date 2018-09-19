const double eps=1e-8;
const int maxn=1e3+5;
typedef double Matrix[maxn][maxn];
// 得到对角阵
void gauss_jordan(Matrix A,int n)
{
    // 求解的增广矩阵，最后的A[i][n]是弟i个未知数的值
    for(int i=0;i<n;i++)
    {
        // 选一行r并和i行交换
        int r=i;
        for(int j=i+1;j<n;j++)
            if(fabs(A[j][i])>fabs(A[r][i]))r=j;

        if(fabs(A[r][i])<eps) continue;
        if(r!=i)
            for(int j=0;j<=n;j++) swap(A[r][j],A[i][j]);
        // 与i+1~n行消元
        for(int k=0;k<n;k++)
        {
            if(k!=i)
            for(int j=n;j>=i;j--) A[k][j]-=A[k][i]/A[i][i]*A[i][j];
        }
    }
}
















