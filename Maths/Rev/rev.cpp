// 线性求1-(p-1)modp的逆元
int main()
{
    A[i]=-(p/i)*A[p%i];
    inv[i]=(p-(p/i))*inv[p%i]%p;
}
