text ='''baby sukhwan tururu turu
very cute tururu turu
in bed tururu turu
baby sukhwan'''
word = text.split()
#print(word)
n = int(input()) - 1
index = n%14 
if index not in [2,3,6,7,10,11]:
    print(word[index])
else :
    k = int(n/14)
    if index%2==0:
        if k >= 3:
            print("tu+ru*"+str(k+2))
        else :
            print(word[index]+str("ru")*k)
    else :
        if k >= 4:
            print("tu+ru*"+str(k+1))
        else :
            print(word[index]+str("ru")*k)

        
    