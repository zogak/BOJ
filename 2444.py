n = int(input())
for i in range(1, 2*n):
    if(i<=n):
        blank = n-i
        star = 2*i-1
        print(" "*blank + "*"*star)
    else:
        blank = i-n
        star = ((2*n-1)-i)*2+1
        print(" "*blank + "*"*star)