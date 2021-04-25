n = int(input())
scores = list(map(int, input().split()))

highest = max(scores)
fixed =[]
for score in scores:
    fixed.append(score/highest*100)

ans = sum(fixed)/n
print(ans)

