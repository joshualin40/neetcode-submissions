class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def backtrack(index, subset):
            if index > n or len(subset) >= k:
                if len(subset) >= k: 
                    res.append(subset[:])
                return 
            
            subset.append(index)
            backtrack(index + 1, subset)
            subset.pop()
            backtrack(index + 1, subset)
        backtrack(1, [])
        return res
