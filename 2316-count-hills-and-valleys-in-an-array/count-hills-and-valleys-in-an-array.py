class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        cnt = 0
        uniq = [nums[0]]

        for i in range(1, len(nums)) :
            if nums[i - 1] != nums[i] : 
                uniq.append(nums[i])

        print(uniq)

        for i in range(1, len(uniq) - 1) : 
            if uniq[i - 1] > uniq[i] and uniq[i] < uniq[i+1] : cnt += 1
            if uniq[i - 1] < uniq[i] and uniq[i] > uniq[i+1] : cnt += 1

        return cnt