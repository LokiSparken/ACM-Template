double add(double a,double b)
{
    if(fabs(a+b)<EPS*((fabs(a)+fabs(b)))) return 0;
    return a+b;
}
struct P
{
    double x,y;
    P(){}
    P(double x,double y):x(x),y(y){}
    P operator - (P p)
    {
        return P(add(x,-p.x),add(y,-p.y));
    }
    double dot(P p)
    {
        return add(x*p.x,y*p.y);
    }
    double det(P p)
    {
        return add(x*p.y,-y*p.x);
    }
}ps[MAXN];
int N;
bool cmp(const P &p,const P &q)
{
    if(p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
vector<P> convex_hull(P *ps,int n)
{
    sort(ps,ps+n,cmp);
    int k=0;
    vector<P> qs(n*2);
    for(int i=0;i<n;++i)
    {
        while(k>1 && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) --k;
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;--i)
    {
        while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) --k;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
double calc(P a,P b)
{
    return (a-b).dot(a-b);
}
void solve()
{
    vector<P> qs=convex_hull(ps,N);
    double res=0;
    for(int i=0;i<qs.size();++i)
        for(int j=0;j<i;++j)
            res=max(res,calc(qs[i],qs[j]));
    printf("%.0f\n",res);
}
