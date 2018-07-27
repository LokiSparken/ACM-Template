/*
 * mat A(m,vec(n))={{0,1,...,n-1}0,{}1,...,{}m-1};初始化
 * 对于矩阵快速幂应有m==n。
 */
typedef vector<ll> vec;
typedef vector<vec> mat;
mat operator*(mat& A, mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int k = 0; k < B.size(); k++)
            if (A[i][k]) // 对稀疏矩阵的优化
                for (int j = 0; j < B[0].size(); j++)
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}
mat Pow(mat A, ll n)
{
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) B[i][i] = 1;
    for (; n; n >>= 1, A = A * A)
        if (n & 1) B = B * A;
    return B;
}

// 数组版
const int N;
struct matrix{long long mat[N][N];};
matrix operator *(matrix a,matrix b)
{
    matrix c;
    memset(c.mat,0,sizeof(c.mat));
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
        {
            if(a.mat[i][k]==0) continue;
            for(int j=0;j<N;j++)
            {
                if(b.mat[k][j]==0) continue;
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
        if(n&1) c=c*a;
        a=a*a;
        n>>=1;
    }
    return c;
}
