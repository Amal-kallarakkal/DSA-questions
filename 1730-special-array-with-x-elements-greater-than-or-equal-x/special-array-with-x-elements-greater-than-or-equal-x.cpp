class Solution {
public:

    int binarySearch(vector<int>& nums, int low, int high) {
        if(low > high) {
            return -1;
        }

        int mid = (high + low)/2;

        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= mid) {
                cnt = nums.size() - i;
                break;
            }
        }
        if(cnt == mid) return mid;
        else if(cnt > mid) return binarySearch(nums, mid + 1, high);
        else return binarySearch(nums,low, high - 1);

        // return -1;
    }

    int specialArray(vector<int>& nums) {
        ios::sync_with_stdio(0);
        sort(nums.begin(), nums.end());

        return binarySearch(nums,0,nums[nums.size() - 1]);
    }
};