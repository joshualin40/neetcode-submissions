class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        visited = set()
        ROWS, COLS = len(grid), len(grid[0])

        def dfs(i,j):
            if min(i,j) < 0 or i == ROWS or j == COLS or grid[i][j] == 0:
                return 1
            if (i,j) in visited:
                return 0

            visited.add((i,j))
            

            return dfs(i+1,j) + dfs(i-1,j) + dfs(i,j+1) + dfs(i,j-1)
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    return dfs(i,j)