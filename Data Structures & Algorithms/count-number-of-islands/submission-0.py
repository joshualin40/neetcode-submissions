class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0
        # def of Island is all edges are water

        # perform DFS on 1s, and record how many times it stops

        # but then i would need to have access to at least a 1 from each island

        # use DFS algortihm and then when it stops, add 1 to res and try diagonally
        ROWS, COLS = len(grid), len(grid[0])

        def dfs(r, c): 
            if (min(r,c) < 0 or r == ROWS or c == COLS or grid[r][c] == '0'):
                return
            
            grid[r][c] = '0'


            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == '1':
                    dfs(i,j)
                    res += 1
        return res