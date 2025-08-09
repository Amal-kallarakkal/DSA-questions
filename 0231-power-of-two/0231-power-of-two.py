class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if (n < 1  or n & (n-1)) : 
            return False

        return True