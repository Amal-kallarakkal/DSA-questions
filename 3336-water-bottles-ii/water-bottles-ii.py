class Solution(object):
    def maxBottlesDrunk(self, numBottles, numExchange):
        numb = 0
        numex = numExchange
        total = numBottles
        empty = numBottles
        while(numb or empty >= numex): 
            while(empty >= numex): 
                empty -= numex
                numex += 1
                numb += 1
                
            total += numb
            empty += numb
            numb = 0
       
        return total

        