class Solution {
    public int maximumDifference(int[] nums) {
        int ans = 0, n = nums.length;
        int[] nextMax = new int[n];
        System.arraycopy(nums, 0, nextMax, 0, n);

        for(int i = n - 2; i >= 0; i--) {
            nextMax[i] = Math.max(nextMax[i+1], nextMax[i]);
        }

        for(int i = 0 ; i < n - 1; i++) {
            ans = Math.max(nextMax[i] - nums[i], ans);
        }
        return (ans > 0) ? ans : -1;
    }
}