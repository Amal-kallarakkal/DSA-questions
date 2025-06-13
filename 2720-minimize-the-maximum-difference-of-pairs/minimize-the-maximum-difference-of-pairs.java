class Solution {

    public boolean solve(int mid, int[] nums, int p) {
        int n = nums.length, cnt = 0, i = 0;
      
        while(i < n - 1) {
            if(nums[i+1] - nums[i] <= mid) {
                i += 2;
                cnt++;
            } else i++;

            if(cnt >= p) {
                return true;
            }
        }
        return false;
    }

    public int minimizeMax(int[] nums, int p) {
        Arrays.sort(nums);
        int ans = 0, n = nums.length, l = 0, h = nums[n -1], mid;
        
        
        while(l <= h) {
            mid = l + (h - l)/2;
            if(solve(mid, nums, p))  {
                ans = mid;
                h = mid - 1;
            } else l = mid + 1;
        }

        return ans;
    }
}