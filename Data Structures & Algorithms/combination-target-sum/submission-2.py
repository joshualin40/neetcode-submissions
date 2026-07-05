class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res  = []


        def backtrack(index, subset, currsum):
            if (index > len(nums) - 1 or currsum >= target):
                if (currsum == target):
                    res.append(subset[:]) # stores copy instead of reference 
                return
            
            subset.append(nums[index])
            backtrack(index, subset, currsum + nums[index])
            subset.pop()
            backtrack(index + 1, subset, currsum)


        backtrack(0, [], 0)
        return res