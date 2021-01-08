def gcd(a, b):
    return b != 0 and gcd(b, a%b) or a
