#include<bits/stdc++.h>
//数字低的项在前面
using namespace std;
const double PI = acos(-1);
struct A{
    double r,i;
    A(double r = 0, double i = 0):r(r), i(i){}
}a[100],b[100];
A operator + (const A& x, const A& y){
    return A(x.r + y.r, x.i + y.i);
}
A operator - (const A& x, const A&y){
    return A(x.r - y.r, x.i - y.i);
}
A operator * (const A& x, const A&y){
    return A(x.r * y.r - x.i *y.i, x.r * y.i + x.i * y.r);
}

void FFT(A x[], int n,int p)
{
    for(int i = 0, t = 0; i < n; ++i){
       if(i > t)swap(x[i], x[t]);
       for(int j = n >> 1; (t ^= j) < j; j >>= 1);
       //二进制反转
    }
    for(int h = 2; h <= n; h <<= 1){
       A wn(cos(p * 2 * PI / h), sin(p * 2 * PI / h));
       //取遍n个复数 且只用取2的幂次
       for(int i = 0; i < n; i += h){
          A w(1,0),u;
          for(int j = i, k = h>>1; j < i + k; ++j){
             u = x[j + k] * w;
             x[j + k] = x[j] - u;
             x[j] = x[j] + u;
             w = w * wn;
          }
       //利用折半以及背角原理进行分治;
       }
    }
    if(p == -1)
        for(int i = 0; i < n; ++i)
           x[i].r /= n;
}
void conv(A a[], A b[], int n){
    FFT(a, n, 1);
    FFT(b, n, 1);
    for(int i = 0; i < n; ++i)
       a[i] = a[i] * b[i];
    FFT(a, n, -1);
}
int main()
{
     int n,m;
     scanf("%d%d",&n,&m);
     int N = 1;
     while(N < n + m - 1)N <<= 1;
     conv(a, b, N);
}














