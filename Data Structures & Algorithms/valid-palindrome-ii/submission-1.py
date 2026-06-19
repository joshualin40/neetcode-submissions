class Solution:
    def validPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1
    
        if self.isValid(s):
            return True
        while l < r: 
            if s[l] != s[r]: 
                if self.isValid(s[:l] + s[l+1:]) or self.isValid(s[:r] + s[r+1:]):
                    return True
            
            l += 1
            r -= 1
        
        return False

    def isValid(self, s: str) -> bool:  
        l = 0
        r = len(s) - 1

        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        
        return True