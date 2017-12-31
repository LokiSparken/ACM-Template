void factorial(int day,int choose)
{
    int num[10000]={1};
    long long digit=1,rem=0;
    for(int i=2;i<=day;i++)
    {
        for(int j=0;j<digit;j++)
        {
            rem=rem+num[j]*i;
            num[j]=rem%10;
            rem/=10;
        }
        while(rem)
        {
            digit++;
            num[digit-1]=rem%10;
            rem=rem/10;
        }
    }
    int cnt=0;
    for(int i=digit-1;i>-1;i--)
        if(num[i]==choose) ++cnt;
    printf("%d \n",cnt);
}
