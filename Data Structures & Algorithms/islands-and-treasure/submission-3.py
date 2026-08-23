class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        ROWS, COLS = len(grid), len(grid[0])
        queue = deque()
        visited = set()
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    queue.append((i,j))
        
        length = 1
        while queue: 
            for i in range(len(queue)): 
                r, c = queue.popleft()

                neighbors = [[1,0], [-1,0], [0, 1], [0, -1]]
                for ar, ac in neighbors: 
                    row, col = r + ar, c + ac
                    if min(row, col) < 0 or row == ROWS or col == COLS or grid[row][col] != 2147483647:
                        continue
                    grid[row][col] = length
                    queue.append((row, col))
            length += 1


        