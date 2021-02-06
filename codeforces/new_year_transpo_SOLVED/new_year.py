input_list = input()
n, t = int(input_list[0]), int(input_list.split(" ")[1])
goal = t - 1
a = input().split(" ")
aList = []
for i in range(n - 1):
    aList.append(int(a[i]))

def expand(stateTuple):
    nextStop = stateTuple[0] + stateTuple[1]
    if nextStop > goal:
        print("NO")
        return
    elif nextStop < goal:
        expand((nextStop, aList[nextStop]))
    else:
        print("YES")
        return

expand((0,aList[0]))
    