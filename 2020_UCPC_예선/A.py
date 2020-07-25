def gcd(a1, a2):
  while (a2 != 0):
    temp = a1 % a2
    a1 = a2
    a2 = temp
  return abs(a1)

def lcm(a1,a2):
    return a1*a2//gcd(a1,a2)

a,b,c,d,e,f =  map(int,input().split())
x, y = None,None

if a==0 or d==0:
    if b<0:
        a = -a
        b = -b
        c = -c
    if e<0:
        d = -d
        e = -e
        f = -f

    if d==0 and b==0:
        x = c//a
        y = f//e
        
    elif a == 0 and e==0:
        y = c//b
        x = f//d

    else :
        lcm_be = lcm(b,e)
        lcm_eb = lcm(b,e)
        lcm_b = lcm_be//b
        lcm_e = lcm_eb//e
        a = a*(lcm_b)
        b = b*(lcm_b)
        c = c*(lcm_b)
        d = d*(lcm_e)
        e = e*(lcm_e)
        f = f*(lcm_e)
        x = (c - f) // (a - d)
        y =  (c - x*a) // b

else :
    if a<0:
        a = -a
        b = -b
        c = -c
    if d<0:
        d = -d
        e = -e
        f = -f

    # print("%dx + %dy = %d"%(a,b,c))
    # print("%dx + %dy = %d"%(d,e,f))

    lcm_ad = lcm(a,d)
    lcm_da = lcm(a,d)
    lcm_a = lcm_ad//a
    lcm_d = lcm_da//d
    # print(lcm_ad,lcm_a,lcm_d)
    a = a*(lcm_a)
    b = b*(lcm_a)
    c = c*(lcm_a)
    d = d*(lcm_d)
    e = e*(lcm_d)
    f = f*(lcm_d)
    # print("%dx + %dy = %d"%(a,b,c))
    # print("%dx + %dy = %d"%(d,e,f))
    y = (c - f) // (b - e)
    x =  (c - b*y) // a

print("%d %d"%(x,y))



'''
from fractions import Fraction
import numpy as np

def simultaneous_eq(a,b):
    if a[0] == 0:
        y = Fraction(a[2], a[1])
        x = Fraction(b[2] - b[1]*y, b[0])
    elif a[1] == 0:
        x = Fraction(a[2], a[0])
        y = Fraction(b[2] - b[0]*x, b[1])
    elif b[0] == 0:
        y = Fraction(b[2], b[1])
        x = Fraction(a[2] - a[1]*y, a[0])
    elif b[1] == 0:
        x = Fraction(b[2], b[0])
        y = Fraction(a[2] - a[0]*x, a[1])
    else:
        a = np.array(a)
        b = np.array(b)
        c = b* Fraction(a[0],b[0])
        d = a - c
        y = Fraction(d[2],d[1])
        x = Fraction(a[2]-a[1]*y,a[0])
    return x, y


a,b,c,d,e,f =  map(int,input().split())
arg1 = [a,b,c]
arg2 = [d,e,f]
ans = simultaneous_eq(arg1,arg2)
print("%d %d"%(ans[0],ans[1]))


'''