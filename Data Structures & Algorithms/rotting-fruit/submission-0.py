class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # vertically/horizontally adjacent: 
        # find the fruit with 2 fruits, and do BFS on each of them
        ROWS, COLS = len(grid), len(grid[0])
        fresh = ROWS * COLS
        res = -1
        
        queue = deque()
        time = 0
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    fresh -= 1
                if grid[i][j] == 2: 
                    queue.append((i,j))
                    fresh -= 1
        while fresh > 0 and queue: 
            for i in range(len(queue)): 
                r, c = queue.popleft()

                neighbors = [[1,0], [-1,0], [0, 1], [0, -1]]
                for ar, ac in neighbors: 
                    row, col = r + ar, c + ac
                    if min(row, col) < 0 or row == ROWS or col == COLS or grid[row][col] != 1:
                        continue
                    grid[row][col] = 2
                    queue.append((row, col))
                    fresh -= 1
            time += 1

                    
        
        return time if fresh == 0 else -1
                        

