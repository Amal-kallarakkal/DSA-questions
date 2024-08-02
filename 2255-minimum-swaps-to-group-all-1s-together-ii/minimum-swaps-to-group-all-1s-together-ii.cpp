
static const int fast = []{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    return 0;
}();

class Solution {
public:
    int minSwaps(vector<int>& a) {
        int win = 0, n = a.size();

        // count the total num of 1s , thats will be the window size => win.
        for(int i = 0 ; i < a.size(); i++) if(a[i]) win++;

        // CREATE a new vector to push the first "win" number of elements at the back to create a cicular array
        vector<int> nums;
        nums.insert(nums.end(), a.begin(), a.end());        
        for(int i = 0; i< win; i++ ) nums.push_back(a[i]);

        int mini = INT_MAX;
        int cnt = 0;
        // find the mini for first "win" elements
        for(int i = 0 ; i < win; i++) {
            if(nums[i] == 0) cnt++;
        }

        mini = min(mini, cnt);
        int j;
        n = nums.size();

        // basic sliding window 
        for(int i = 0 ; i < n - win; i++) {
            j = i + win;
            if(nums[i] == 0) cnt--;
            if(nums[j] == 0) cnt++;
            mini = min(mini, cnt);
        }

        return mini;

    }
};