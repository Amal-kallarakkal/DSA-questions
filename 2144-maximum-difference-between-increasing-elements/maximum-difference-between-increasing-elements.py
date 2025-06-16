class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        MaxNext = nums.copy()
        n = len(nums)
        ans = 0

        for i in range(n - 2, -1, -1) :
            MaxNext[i] = max(MaxNext[i], MaxNext[i + 1]);
        
        for i in range(n):
            ans = max(MaxNext[i] - nums[i], ans);
            # print(MaxNext[i], end = " ")

        return ans if ans > 0 else -1