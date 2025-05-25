# from collections import Counter
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        freq = Counter(words)
        hasCenter = False
        ans = 0

        for key in list(freq.keys()):
            rev = key[::-1]
            if key == rev:
                ans += (freq[key]//2)*4
                if freq[key]%2 == 1 and not hasCenter:
                    hasCenter = True
            else:
                ans += min(freq[rev], freq[key]) * 4
                freq[rev] = 0
        
        if hasCenter: ans += 2
        return ans