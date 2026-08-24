class Solution:
    def longestPalindrome(self, s: str) -> str:
        # consider all middle chars as centers of palindromes
        n = len(s)
        res = ""

        def dp(i): # define DP function that recieves the index of centers,
            # TODO: recursively find the largest palindrome with s[i] as center
            substring = s[i]
            begin = end = i
            while begin > 0 and s[begin - 1] == s[begin]:
                begin -= 1
            while end < n - 1 and s[end + 1] == s[end]:
                end += 1
            while begin - 1 >= 0 and end + 1 < n and s[begin-1] == s[end+1]:
                substring = s[begin-1] + substring + s[end+1]
                begin -= 1
                end += 1
            return s[begin:end + 1]
        
        for k in range(n):
            curr = dp(k)
            if len(curr) > len(res):
                res = curr
        return res



                
        

        # iterate over str s and return the max legnth of dp[i]
