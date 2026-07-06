class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        chosen = [False] * len(nums)
        # create a list of bools 
        # at each backtrack choose the next element that hasnt been chosen 
        def backtrack(index, subset, chosen):
            if (len(subset) == len(nums)):
                res.append(subset[:])
                return
            for index in range(len(nums)):
                if not chosen[index % len(nums)]:
                    subset.append(nums[index % len(nums)])
                    chosen[index % len(nums)] = True
                    backtrack(index + 1, subset, chosen)
                    subset.pop()
                    chosen[index % len(nums)] = False

        backtrack(0, [], chosen)
        return res
            


