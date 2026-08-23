class Solution:
    def climbStairs(self, n: int) -> int:

        if n <= 2: 
            return n 
        
        k = 3
        dp = [0] * (n + 1)
        dp[1], dp[2] = 1,2
        while k <= n: 
            dp[k] = dp[k-1] + dp[k-2]
            k+=1

        return dp[n]
    