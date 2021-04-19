#max value
cnt = 0
ans = 0
for i in range(1,10):
    n = int(input())
    if n > ans:
        cnt, ans = i, n

print(ans)
print(cnt)