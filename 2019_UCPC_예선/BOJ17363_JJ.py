
#조건정리
text = '''.	온점	46	.
O	대문자 O	79	O
-	하이픈	45	|
|	세로 바	124	-
/	슬래시	47	\\
\	역슬래시	92	/
^	캐럿	94	<
<	왼쪽 부등호	60	v
v	소문자 V	118	>
>	오른쪽 부등호	62	^'''
text = text.split('\n')
rule = []
for i in range(10):
    tmp = text[i].split( )
    rule.append([tmp[0],tmp[-1]])

#print(rule)

#입력
x,y = map(int,input().split())
o_d = []
for i in range(x):
    o_d.append(list(input()))

#print(o_d)

#변환
for i in range(x):
    for j in range(y):
        for k in range(len(rule)):
            #print(o_d[i][j]) 
            #print(rule[k][0])
            if o_d[i][j] == rule[k][0]:
                o_d[i][j] = rule[k][1]
                break

for i in range(y-1,-1,-1):
    for j in range(x):
        print(o_d[j][i],end="")
    print()
