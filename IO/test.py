T = int(input().split())
for case in range(T):
    line = map(int, input().strip().split())
    n, a = line[0], line[1:]
    
    sum = 0
    for i in range(n):
        sum += a[i]
    print (sum)