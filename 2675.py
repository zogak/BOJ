t = int(input())
while t>0:
    t = t-1
    r, s =input().split()
    r = int(r)
    p=''
    for alpha in s:
        for i in range(r):
            p+=alpha
    print(p)