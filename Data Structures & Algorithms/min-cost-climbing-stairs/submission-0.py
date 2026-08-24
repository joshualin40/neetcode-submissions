class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # opposite of house robber 
        # cache should store the minimum cost from index i onwards 
        n = len(cost)
        cache = [-1] * n
        def memoization(index): 
            if index >= n:
                return 0
            if cache[index] != -1:
                return cache[index]
            cache[index] = min(cost[index] + memoization(index + 1), cost[index] + memoization(index+2))
            return cache[index]

        return min(memoization(0), memoization(1))
            