#OX quiz

t = int(input())
for i in range(0, t):
    check = 0
    s = 0
    ans = input()
    for n in ans:
        if n == "O":
            check = check + 1
            s = s + check
        else:
            check = 0
    print(s)