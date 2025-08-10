class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_map<int, int> mp, mp2;
        vector<int> nums;
        int m;
        if((n&(n-1)) == 0) return true;
        while(n) {
            mp[n%10]++;
            nums.push_back(n%10);
            n /= 10;
        }
        sort(nums.rbegin(), nums.rend());
        int top = 0;
        for(int i : nums) {
            top = top*10 + i;
        }
        for(int i = 2; i <= top; i = 2*i) {
            mp2.clear();
            m = i;
            while(m) {
                mp2[m%10]++;
                m /= 10;
            }
            if(mp == mp2) return true;
        }

        return false;
    }
};