class Solution:
    def reformat(self, s: str) -> str:
        letras = [c for c in s if c.isdigit()]
        nums = [c for c in s if not c.isdigit()]
        if abs(len(letras) - len(nums)) > 1:
            return ""
        
        if len(letras) > len(nums):
            first = letras
            second = nums
        else:
            first = nums
            second = letras
        
        ans = ""
        i = 0
        j = 0
        while i < len(first) or j < len(second):
            if i < len(first):
                ans += first[i]
                i += 1
            if j < len(second):
                ans += second[j]
                j += 1
        return ans