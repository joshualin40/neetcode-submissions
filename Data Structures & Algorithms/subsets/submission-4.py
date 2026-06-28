class Solution:
    def backtrack(self, nums, index, subset):
        if index >= len(nums):
            return
        
        subset.append(nums[index])
        self.res.append(subset[:])
        self.backtrack(nums, index + 1, subset)
        subset.pop()
        self.backtrack(nums, index + 1, subset)

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.res = []
        subset = []
        self.backtrack(nums, 0, subset)
        self.res.append([])
        return self.res
        