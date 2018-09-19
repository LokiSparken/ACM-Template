/*一、set
set和multiset用法一样，multiset允许重复元素
利用set从大到小排序（自定义排序函数）*/
struct classcmp
{
    bool operator()(const int &lhs,const int &rhs)const
    {return lhs>rhs;}
};
multiset<int,classcmp> s;
// 结构体自定义排序函数
struct Node { int x,y; };
struct classcmp
{
    bool operator()(const Node &a,const Node &b)const
    {
        if(a.x!=b.x) return a.x<b.x;
        else return a.y>b.y;
    }// 按x从小到大，按y从大到小
};
multiset<Node,classcmp> s;
multiset<Node,classcmp>::iterator it;// 若定义迭代器也要带排序函数
// 函数
erase()// 删除元素（参数为元素值或迭代器，multi会删光值的每一个）
lower_bound()// 返回指向大于（或等于）某值的第一个元素的迭代器
upper_bound()// 返回大于某个值元素的迭代器
equal_range()// 返回集合中与给定值相等的上下限两个迭代器

// 二、string
s1.assign(s2);
s1.assign(s2,lenth);
s1.assign(s2,start,lenth);
s1.assign(times,char1);
s1.assign(start,end);
s1.at(pos);
