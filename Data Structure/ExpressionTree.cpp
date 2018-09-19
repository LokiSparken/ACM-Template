int lch[maxn],rch[maxn];
char op[maxn];
int nc=0;// 结点数
int build_tree(char*s,int x,int y)
{
     int i,c1=-1,c2=-1,p=0;
     int u;
     if(y-x==1)
     {
         u=++nc;
         lch[u]=rch[u]=0;op[u]=s[x];
         return u;
     }
     for(i=x;i<y;i++)
     {
         switch(s[i])
         {
             case'(':p++;break;
             case')':p--;break;
             case'+':case'-':if(!p)c1=i;break;
             case'*':case'/':if(!p)c2=i;break;
         }
     }
     if(c1<0) c1=c2;
     if(c1<0) return build_tree(s,x+1,y-1);
     u=++nc;
     lch[u]=build_tree(s,x,c1);
     rch[u]=build_tree(s,c1+1,y);
     op[u]=s[c1];
     return u;
}
