
def nthNum(nMinusOneNum):
    return nMinusOneNum*10 + 7

def main():
    K = int(input())

    crawler = 7
    found = False
    i = 1

    if (K % 2 ==0) or (K % 5 == 0):
        print(-1)
    else:
        a = [0 for i in range (K+1)]
        a[0] = 7
        for i in range (1, K+1):
            a[i] = (a[i-1]*10 + 7) % K
        a[0] = a[0] % K
        for i in a:
            if i == 0:
                print(a.index(i) + 1)
                found = True
                break
        if not found:
            print(-1)
    
main()