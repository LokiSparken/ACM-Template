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
};
void rotate(node* &o,int d)
{
    //d=0是左旋,d=1是右旋
    node*k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;o=k;
}
void insert(node* &o,int x)
{
    if(o==NULL) o=new node(x);
    else
    {
        int d=o->cmp(x);    //堆的性质   当d=-1的时候要根据题目来
        insert(o->ch[d],x); //插入相应的子树
        if(o->ch[d]->r>o->r) //比较优先级
        rotate(o,d^1);       //调整旋转
    }
}
void remove(node* &o,int x)
{
    int d=o->cmp(x);
    if(d==-1)  //和该结点的键值相同；
    {
        if(o->ch[0]==NULL)o=o->ch[1];
        else if(o->ch[1]==NULL)o=o->ch[0];
        else
        {
            int d2=(o->ch[0]->r>o->ch[1]->r?1:0);
            rotate(o,d2);remove(o->ch[d2],x);  //旋转,其次再继续从寻找到的位置出发
        }
    }
    else remove(o->ch[d],x);
}
int find(node*&o,int x)
{
    while(o!=NULL)
    {
        int d=o->cmp(x);
        if(d==-1)return 1;//找到了
        else
         o=o->ch[d];
    }
    return 0;
}
