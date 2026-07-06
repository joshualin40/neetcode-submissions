class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        def backtrack(index, subset): 
            if index >= len(nums) or len(subset) == len(nums):

                return 
            
            subset.append(nums[index])
            res.append(subset[:])
            backtrack(index + 1, subset)
            subset.pop()
            while index < len(nums) - 1 and nums[index] == nums[index + 1]:
                index += 1
            backtrack(index + 1, subset)
        backtrack(0,[])
        res.append([])
        return res
            
