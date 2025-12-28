def is_valid(row, col, board): 
    # проверка, бьются ли ферзи в той же строке или диагоналях 
    for i in range(row): 
        if board[i] == col or board[i] - i == col - row or board[i] + i == col + row: 
            return False 
    return True 
def solve(size, row, board, results): 
    # если все столбцы заполнены, добавляем расстановку ферзей в результаты 
    if row == size: 
        results.append(board[:]) 
        return 
    # пытаемся поставить ферзя в каждую строку текущего столбца 
    for col in range(size): 
        if is_valid(row, col, board): 
            board[row] = col 
            solve(size, row+1, board, results) 
            board[row] = -1 
def find_all_solutions(size): 
    results = [] 
    board = [-1] * size 
    solve(size, 0, board, results) 
    return results
 
n = int(input())
all_solutions = find_all_solutions(n) # найдем все расстановки ферзей на доске 
c = 0
if n>=4:
    for solution in all_solutions: 
        c+=1
    print(c) 
elif n==1:
    print(1)
else:
    print(0)
