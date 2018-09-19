struct node
{
   node *ch[2];
   int r; //优先级rank,这个数值越大,优先级越高。
   int v; //值,满足左子树的值小于父亲，右子树的值大于父亲
   int s; //size
   node(int v):v(v){ch[0]=ch[1]=NULL;r=rand();s=1;}//new node(v);
   int cmp(int x)const
   {
       if(x==v)return -1;
       return x<v?0:1;
   }
   void maintain()   //写在封装的结构体里面
{
    s=1;
    if(ch[0]!=NULL)s+=ch[0]->s;
    if(ch[1]!=NULL)s+=ch[1]->s;
}
};
//rank tree名次树
//名次树中每个结点新加域size。表示以它为根的树的结点多少
//Kth(k):找出第k小的元素；
//Rank(x):值x的名词；
void rotate(node* &o,int d)
{
    //d=0是左旋,d=1是右旋
    node*k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();k->maintain();o=k;
}
void insert(node* &o,int x)
{
    if(o==NULL)
    {
        o=new node(x);
    }
    else
    {
        int d=o->cmp(x);    //堆的性质   当d=-1的时候要根据题目来
        insert(o->ch[d],x); //插入相应的子树
        if(o->ch[d]->r>o->r) //比较优先级
        rotate(o,d^1);       //调整旋转
    }
    o->maintain();
}
int kth(node *o,int k)
{
    if(o==NULL||k<=0||k>o->s)return 0;
    int s=(o->ch[1]==NULL?0:o->ch[1]->s);
    if(k==s+1)return o->v;
    else if(k<=s)return kth(o->ch[1],k);  //因为满足二叉索引树的性质
    else return kth(o->ch[0],k-s-1);
}
void mergeto(node* &src,node* &dest)
{
    if(src->ch[0]!=NULL)mergeto(src->ch[0],dest);
    if(src->ch[1]!=NULL)mergeto(src->ch[1],dest);
    insert(dest,src->v);
    delete src;
    src=NULL;
}
void removetree(node* &x)
{
    if(x->ch[0]!=NULL)removetree(x->ch[0]);
    if(x->ch[1]!=NULL)removetree(x->ch[1]);
    delete x;
    x=NULL;
}
