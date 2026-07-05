class Solution:
    def backtrack(self, nums: List[int], subset: List[int], currsum, index) -> List[List[int]]:
        if (index > len(nums) - 1 or currsum >= self.target):
            if (currsum == self.target):
                self.res.append(subset[:])
            return 

        subset.append(nums[index])
        self.backtrack(nums, subset, currsum + nums[index], index)
        subset.pop()
        self.backtrack(nums, subset, currsum, index + 1)
        
        

    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        self.res = []
        self.target = target
        # when backtracking, 
        subset = []
        currsum = 0
        self.backtrack(nums, subset, currsum, 0)
        return self.res