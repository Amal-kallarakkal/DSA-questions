class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        nums2 = [0]*(n + 1)

        for i in queries:
            nums2[i[0]] += 1
            nums2[i[1] + 1] -= 1

        for i in range(1, n):
            nums2[i] += nums2[i - 1]

        for i in nums2: 
            print(i, end = " ")

        for i in range(0, n):
            if nums[i] > nums2[i]: return False;
        
        return True;

        