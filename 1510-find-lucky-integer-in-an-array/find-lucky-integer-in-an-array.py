class Solution:
    def findLucky(self, arr: List[int]) -> int:
        ans = -1
        arr.sort()
        mp = defaultdict(int)
        for x in arr:
            mp[x] += 1
            

        for key, value in mp.items():
            if key == value : ans = key

        return ans