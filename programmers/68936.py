def solution(arr):
    
    def chk(sx, sy, ex, ey):
        val = arr[sy][sx] 
        for i in range(sy, ey):
            for j in range(sx, ex):
                if arr[i][j] != val:
                    return False
        return True
    
    def init():
        n = len(arr)
        zeros = 0
        ones = 0
        for i in range(n):
            for j in range(n):
                if arr[i][j] == 1:
                    ones += 1
                else:
                    zeros += 1
        return [zeros, ones]
    
    def solve(sx, sy, ex, ey):
        if sx + 1 >= ex:
            return
        if chk(sx, sy, ex, ey) == True:
            val = arr[sy][sx]
            ans[val] -= (ex - sx) ** 2 - 1
            return
        else:
            midx = (sx + ex) // 2
            midy = (sy + ey) // 2
            solve(sx, sy, midx, midy)
            solve(midx, midy, ex, ey)
            solve(sx, midy, midx, ey)
            solve(midx, sy, ex, midy)
        return
    
    n = len(arr)
    ans = init() 
    solve(0, 0, n, n)
    return ans