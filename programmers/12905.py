def solution(board):
    answer = 1234
    ny = len(board)
    nx = len(board[0])
    def chk():
        ret = False
        for y in range(1, ny):
            for x in range(1, nx):
                if board[y][x] == 0:    
                    continue 
                board[y][x] = min([board[y-1][x], board[y][x-1], board[y-1][x-1]]) + 1
        return             
    chk()
    
    # [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    return max(map(max,board)) ** 2