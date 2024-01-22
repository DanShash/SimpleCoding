#Python Practice begining tutorial Date:12/21/2023
def is_valid_move(grid, row, col, number):
     
     for x in range(9):
         if grid[row][x] == number:
            return False 
         
     for x in range(9):
        if grid[x][col] == number: 
            return False 
          
     corner_row = row - row % 3
     corner_col = col - col % 3
     for x in range(3):
         for y in range(3):
             if grid[corner_row +x][corner_col + y] == number:
                 return False
     return True
def solve(grid, row, col):

    if col == 9: 
        if row == 8:
            return True 
        row += 1 
        col = 0 

    if grid[row][col]> 0:
        return solve (grid, row ,col +1)
    
    for num in range(1, 10):

        if is_valid_move(grid, row, col, num):

            grid[row][col] = num 
            if solve (grid, row, col +1):
               return True
            grid[row][col] = 0

    return False
    
grid = [
    [0, 1, 3, 8, 4, 0, 9, 2, 6],
    [6, 8, 7, 2, 5, 0, 4, 1, 0],
    [9, 0, 0, 6, 3, 0, 0, 0, 0],
    [7, 0, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 9, 0, 8, 1, 3, 0],
    [0, 0, 8, 0, 0, 4, 0, 6, 5],
    [4, 7, 0, 0, 0, 0, 0, 9, 1],
    [0, 0, 0, 0, 0, 6, 5, 0, 0],
    [0, 5, 1, 4, 0, 0, 0, 0, 0],
]

if solve(grid, 0, 0):
    #Print solved sudoku grid
    for row in grid:
        print(row)

else:
    print("Sudoku grid cannot be solved.")
