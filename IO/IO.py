# while(scanf("%d",&n)==1)
while True:
    try:
        n=int(input())
        print(n)
    except EOFError:
        break

# while(scanf("%d%d",&a,&b)==2)
while True:
    try:
        a, b = map(int, input().strip().split()) # strip去掉前导和末尾的空格，split切片
        print (a + b, end = ' ') 
        # py3的print是函数一定要括号，py2不要，最后括号外加逗号不自动换行，end不加参数默认\n
    except EOFError:
        break
    
# int T;scanf("%d",&T);while(T--){scanf("%d%d",&n,&m)==2}
T = int(input().strip())
for case in range(T):
    n, m = map(int, input().strip().split())
    print(n,m)
    
# 条件结束
while True:
    n, m = map(int, input().strip().split())
    print(n,m)
    if n == 0 and m == 0:
        break
    
# n a1 a2 a3 ... an
T = int(input().strip())
for case in range(T):
    line = map(int, input().strip().split())
    n, a = line[0], line[1:]
    
    sum = 0
    for i in range(n):
        sum += a[i]
    print (sum)