n,m = map(int,input().split())
card = list(map(int,input().split()))
for _ in range(m):
    card.sort()
    card[0],card[1] = card[0]+card[1],card[0]+card[1]
print(sum(card))