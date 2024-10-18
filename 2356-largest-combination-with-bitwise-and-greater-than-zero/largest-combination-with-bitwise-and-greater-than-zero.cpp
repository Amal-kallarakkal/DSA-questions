class Solution {
public:
    string binary(int n) {
        string s = "";
        while(n) {
            if(n%2) s += '1';
            else s += '0';
            n /= 2;
        }
        return s;
    }
    int largestCombination(vector<int>& nums) {
        vector<int> bitmap(24);
        string s ;
        for(int i = 0 ; i < nums.size(); i++) {
            s = binary(nums[i]);
            for(int j = 0 ; j < s.size(); j++) {
                if(s[j] == '1') bitmap[j]++;              
            }
        }

        sort(bitmap.begin(), bitmap.end());
        return bitmap[23];
    }
};