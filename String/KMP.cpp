/*
 * fail为最终直接跳到底的地方，fail2原始跳转点。
 */
int fail[maxn],fail2[maxn];
void getfail(string &s,int fail[])
{
    int m=s.size();
    fail[0]=0,fail[1]=0;
    fail2[0]=fail2[1]=0;
    for(int i=1;i<m;++i)
    {
        int j=fail2[i];
        while(j && s[i]!=s[j]) j=fail2[j];
        fail2[i+1] = fail[i+1]=(s[i]==s[j])?j+1:0;
        if(fail[i+1]==j+1 && s[i+1]==s[j+1]) fail[i+1]=fail[j+1];
    }
}