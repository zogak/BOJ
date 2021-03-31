#alarm clock
h,m = input().split()
h = int(h)
m = int(m)

if m>=45 and m<=59:
    m -= 45
    print(h,m)

else:
    temp = 45 - m
    m = 60 - temp
    if h==0:
        print(23, m)
    else:
        print(h-1,m)

