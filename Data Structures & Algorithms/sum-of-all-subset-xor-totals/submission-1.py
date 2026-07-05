class Solution:
    def backtrack(self, nums: List[int], subset: List[int], i: int) -> None: 
        if (i >= len(nums)):
            return
        subset.append(nums[i])
        
        XOR = 0
        for num in subset:
            XOR ^= num
        self.res += XOR     
        

        self.backtrack(nums, subset, i + 1)
        subset.pop()
        self.backtrack(nums, subset, i + 1)
        
    def subsetXORSum(self, nums: List[int]) -> int:
        self.res = 0
        subset = []
        self.backtrack(nums, subset, 0)

        return self.res



        # choose either to 