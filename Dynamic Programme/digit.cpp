#include<bits/stdc++.h>//sum%(x*n)%x=sum%x;
using namespace std;
typedef long long ll;
int num[20];
ll dp[20][state];
ll dfs(int pos,/*state*/,int lead/*ǰ��0*/,int limit/*�Ͻ�*/)
{
    if(pos==-1)return 1;//�����
    if(!limit&&dp[pos][state]!=-1)return dp[pos][state];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;i++)
    {
        if()...
            else if()...
    ans+=dfs(pos-1,/*״̬ת��*/,lead&&i==0,limit&&i==a[pos])//�����������������

    }
    if(!limit&&!lead)dp[pos][state]=ans;
    //���粻����62��ô����ֱ�Ӽ�¼�ǲ���6  ��10��ʾ
    //����֮���״̬������ظ��Ϳ���ֱ������
    return ans;
}
ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,/*״̬*/,1,1);
    //�տ�ʼ���λ���������Ʋ�����ǰ�����,
    //��Ȼ�����λ��Ҫ�ߵ�һλ��Ϊ0��
}
int main()
{

}






