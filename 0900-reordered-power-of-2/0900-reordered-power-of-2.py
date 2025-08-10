class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        if n & (n-1) == 0 : 
            return True
        
        def Digit_sig(x) :
            return tuple(sorted(str(x)))

        TwoPowerSet = {Digit_sig(1<<i) for i in range(31)}

        if Digit_sig(n) in TwoPowerSet : return True
        
        return False