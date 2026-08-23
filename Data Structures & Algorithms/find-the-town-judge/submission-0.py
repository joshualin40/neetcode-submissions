class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        adjList = {i+1: set() for i in range(n)}
        candidates = {}

        for a, b in trust:
            adjList[a].add(b)

        # first identify candidates
        for person, trusts in adjList.items(): 
            if not trusts: # person trusts nobody
                candidates[person] = 1

        if not candidates or len(candidates) > 1: # if there are no potential candidates, return -1
            return -1
        
        thecandidate =  next(iter(candidates))
        
        for person, trust in adjList.items():
            # if any candidate doesnt show up in trust list, remove them. skip the candidate
            if person == thecandidate:
                continue
            if thecandidate not in trust:
               return -1

        return thecandidate
        
        


