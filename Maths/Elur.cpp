const int maxn=1e5+5;
struct Num
{
    int count;//每个数的质因数个数
    int prime[16];//每个数的质因数数组
}N[maxn];
int Elur[maxn];//欧拉函数值
void ELUR()//欧拉函数
{
    Elur[1]=1;
    for(int i=0;i<=1e5;i++)
        N[i].count=0;
    for(int i=2;i<=1e5;i++)
    {
        if(!Elur[i])
        {
            for(int j=i;j<=1e5;j+=i)
            {
                if(!Elur[j])Elur[j]=j;

                Elur[j]=Elur[j]*(i-1)/i;
                N[j].prime[N[j].count]=i;
                N[j].count++;
            }
        }
    }
}
int main()
{
    ELUR();
    for(int i=1;i<=20;i++)
        {
            cout<<N[i].count<<endl;
            int c=0;
            while(N[i].prime[c])
                cout<<N[i].prime[c++]<<"  ";
            cout<<endl;
        }
}