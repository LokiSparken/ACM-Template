#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
vector<int> G[MAXN*2];
bool mark[MAXN*2];
int S[MAXN*2],c;
int n,m;
void init()
{
    for(int i=0;i<MAXN*2;++i) G[i].clear();
    memset(mark,0,sizeof(mark));
    memset(S,0,sizeof(S));
}
void add(int x,int xval,int y,int yval)// x的xval^1和y的yval^1是矛盾的
{
    x=x*2+xval,y=y*2+yval;
    G[x^1].push_back(y);
    G[y^1].push_back(x);
}
bool dfs(int x)
{
    if(mark[x^1]) return false;
    if(mark[x]) return true;
    mark[x]=true;
    S[c++]=x;
    for(int i=0;i<G[x].size();++i)
        if(!dfs(G[x][i])) return false;
    return true;
}
bool solve()
{
    for(int i=0;i<n*2;i+=2)
        if(!mark[i] && !mark[i^1])
        {
            c=0;
            if(!dfs(i))
            {
                while(c>0) mark[S[--c]]=false;
                if(!dfs(i^1)) return false;
            }
        }
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        init();
        while(m--)
        {
            int id1,id2,v1,v2;
            scanf("%d%d%d%d",&id1,&id2,&v1,&v2);
            add(id1,v1^1,id2,v2^1);
        }
        if(solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
