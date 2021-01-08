def solution(n):
    answer = 0
    
    def toDigit(n):
        temp = ""
        while n > 0:
            temp = str(n % 2) + temp
            n = n // 2
        return temp
    
    def FromDigit(digit):
        ret = 0
        l = len(digit)
        cnt = 0
        for val in digit:
            cnt += 1
            if int(val) == 0:
                continue 
            ret += 2 ** (l - cnt)
        return ret
    
    d = toDigit(n)
    d = "0" + d
    print(d)
    
    for i in range(len(d)-1, -1, -1):
        if d[i-1:i+1] == "01":
            cnt = d.count("1")
            l = len(d)
            d = d[:i-1] + "10"
            d = d + "0" * (l - len(d) - cnt + d.count("1")) + "1" * (cnt - d.count("1"))
            print(d)
            print(d.count("1"))
            break
    print(d)
    return FromDigit(d)