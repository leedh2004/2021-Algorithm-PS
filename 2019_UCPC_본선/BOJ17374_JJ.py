t = int(input())
for _ in range(t):
    P, Q, A, B, C, D = map(int,input().split())
    bit = P
    coin = int(Q/C)*D
    x1 = int((bit-coin)/(A+B))
    x2 = x1+1
    x3 = x1-1
    print(max( min(bit-A*x1,coin+B*x1),min(bit-A*x2,coin+B*x2),min(bit-A*x3,coin+B*x3),0))
