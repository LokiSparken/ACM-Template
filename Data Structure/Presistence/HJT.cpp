// 可持久化权值线段树
const int maxn=1e5+5;
int lson[maxn*20],rson[maxn*20],sum[maxn*20];
// lson[i],rson[i]为结点i左右子树编号,sum维护的信息,本题中为所管辖数字区间内的数出现多少次
int a[maxn],rt[maxn],cnt;
int n,m;
int id(int x){return lower_bound(temp.begin(),temp.end(),x)-temp.begin()+1;}
void update(int l,int r,int value,int pre,int &cur)
/**
 * 当前维护的区间l,r和要去更新的value，
 * 要移植的前置版本在该处的编号pre，现正创的新版本的当前结点编号cur（更新时给它打编号所以引用）
**/
{
    // 复制前置版本的信息
    ++cnt;
    lson[cnt]=lson[pre],rson[cnt]=rson[pre],sum[cnt]=sum[pre];
    // 因为要从这条分岔下去更新，所以这里的信息要变化
    ++sum[cnt];
    // 记录这个新结点的编号
    cur=cnt;
    if(l==r) return ;// 到底，更新完毕
    int mid=(l+r)>>1;// 否则继续向下
    if(value<=mid) update(l,mid,value,lson[pre],lson[cur]);
    else update(mid+1,r,value,rson[pre],rson[cur]);
}
int query(int l,int r,int k,int pre,int last)
/**
 * 当前查询的区间范围l,r和要查的第k大
 * 查询的版本左右两端编号
**/
{
    if(l==r) return l;// 到底，找到所查第k大的值（离散化后）
    int mid=(l+r)>>1;
    // 否则看右端版本小的一半数有多少个,减去左端版本的个数,即查询版本内小的那一半数有多少个
    int s=sum[lson[last]]-sum[lson[pre]];
    // 如果个数比k大，说明第k大个在小的那半数里，也就是左子树中
    if(s>=k) return query(l,mid,k,lson[pre],lson[last]);
    else return query(mid+1,r,k-s,rson[pre],rson[last]);
    // 个数比k小，转化为在大的那半数里求第k-sum大的数
}