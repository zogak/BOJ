y = int(input())
def decide(y):
    if (y%4==0 and y%100 !=0) or y%400==0:
        return 1
    return 0

print(decide(y))