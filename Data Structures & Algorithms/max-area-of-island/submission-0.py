class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        res = 0
        ROWS, COLS = len(grid), len(grid[0])

        def dfs(r, c, nodes): 
            if (min(r,c) < 0 or r == ROWS or c == COLS or grid[r][c] == 0):
                return
            grid[r][c] = 0
            nodes.append((r,c))

            dfs(r+1, c, nodes)
            dfs(r-1, c, nodes)
            dfs(r, c+1, nodes)
            dfs(r, c-1, nodes)
            return
        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    nodes = []
                    dfs(i,j, nodes)

                    if len(nodes) > res:
                        res = len(nodes)
        return res