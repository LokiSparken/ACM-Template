// 空间：O(n*size)，时间：O(nlog(size))
// 数组版
const int maxn = 100005;
const int SIZE = 26;

struct Palindromic_Tree
{
    int next[maxn][SIZE]; // next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[maxn];       // fail指针，失配后跳转到fail指针指向的节点
    int cnt[maxn];        // i表示的本质不同的串个数（count()一遍后正确）
    int num[maxn];        // i表示的最长回文串最右端为回文串结尾的回文串个数
    int len[maxn];        // len[i]表示节点i表示的回文串的长度
    int S[maxn];          // 存放添加的字符
    int last;             // 指向上一个字符所在的节点，方便下一次add
    int n;                // 字符数组指针
    int p;                // 节点指针

    int newnode(int l)
    { //新建节点
        for (int i = 0; i < SIZE; ++i)
            next[p][i] = 0;
        cnt[p] = 0, num[p] = 0;
        len[p] = l;
        return p++;
    }

    void init()//初始化
    { 
        p = 0, n = 0, last = 0;
        newnode(0),newnode(-1);
        S[n] = -1;fail[0] = 1; //开头放个字符集中没有的字符减少特判
    }

    int get_fail(int x)
    { //和KMP一样，失配后找一个尽量最长的
        while (S[n - len[x] - 1] != S[n])
            x = fail[x];
        return x;
    }

    void add(int c)
    {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last); //通过上一个回文串找这个回文串的匹配位置
        if (!next[cur][c])
        {                                             //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode(len[cur] + 2);          //新建节点
            fail[now] = next[get_fail(fail[cur])][c]; //和AC自动机一样建立fail指针，以便失配后跳转
            next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = next[cur][c];
        cnt[last]++;
    }

    void count()
    {
        for (int i = p - 1; i >= 0; --i)
            cnt[fail[i]] += cnt[i];
        //父亲累加儿子的cnt，因为如果fail[v]=u，则u一定是v的子回文串！
    }
};
// 邻接表，空间稍优，时间略慢
struct PAM
{
    vector<pair<int, int>> next[maxn];
    int fail[maxn], num[maxn], len[maxn];
    ll cnt[maxn];
    int s[maxn], n, p, last, sum;

    void init()
    {
        p = 0,sum = 0, last = 0, n = 0;
        newnode(0), newnode(-1);
        s[n] = -1;
        fail[0] = 1;
    }
    int newnode(int w)
    {
        next[p].clear();
        cnt[p] = num[p] = 0;
        len[p] = w;
        return p++;
    }
    int get_fail(int x)
    {
        while (s[n - len[x] - 1] != s[n])
            x = fail[x];
        return x;
    }
    int add(int c)
    {
        c -= 'a';
        s[++n] = c;
        int cur = get_fail(last);
        int flag = 0;
        for (int i = 0; i < next[cur].size(); i++)
            if (next[cur][i].first == c)
            {
                last = next[cur][i].second;
                cnt[last]++;
                return num[last];
            }
        int now = newnode(len[cur] + 2);
        int fi = get_fail(fail[cur]);
        flag = 0;
        for (int i = 0; i < next[fi].size(); i++)
            if (next[fi][i].first == c)
            {
                flag = next[fi][i].second;
                break;
            }
        fail[now] = flag;
        next[cur].push_back(make_pair(c, now));
        num[now] = num[flag] + 1;
        last = now;
        cnt[now]++;
        return num[now];
    }
    void count()
    {
        for (int i = p - 1; i > 1; i--)
            cnt[fail[i]] += cnt[i];
    }
};