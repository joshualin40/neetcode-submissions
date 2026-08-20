class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])

        if grid[0][0] == 1 or grid[ROWS-1][COLS-1] == 1: 
            return -1

        visit = set() # visited set
        queue = deque() 
        visit.add((0,0))
        queue.append((0,0))
        
        length = 1
        while queue: 
            for i in range(len(queue)):
                r, c = queue.popleft()
                if r == ROWS - 1 and c == COLS - 1: 
                    return length 

                neighbors = [[0, 1], [0, -1], [1, 0], [-1, 0], [1,1], [1,-1], [-1, 1], [-1, -1]]

                for ar, ac in neighbors:
                    if min(ar + r, ac + c) < 0 or ar + r == ROWS or ac + c == ROWS or (ar + r, ac + c) in visit or grid[ar + r][ac + c] == 1:
                        continue
                    queue.append((r + ar,c + ac))
                    visit.add((r + ar,c + ac))
                
            length += 1
        return -1



