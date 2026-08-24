class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        cache = [-1] * n

        def memoization(index):
            if index >= n:
                return 0
            if cache[index] != -1:
                return cache[index]
            cache[index] = nums[index] + max(memoization(index + 2), memoization(index + 3))
            return cache[index]

        return max(memoization(0), memoization(1))