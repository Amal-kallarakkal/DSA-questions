class Solution {
public:
    void solve(string temp, string &ans, unordered_set<string> &set, int &n) {
        if(ans != "") return;
        if(temp.size() >= n) {
            if(!set.count(temp)) ans = temp;
            return; 
        }
        solve(temp + '0', ans, set, n);
        solve(temp + '1', ans, set, n);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        unordered_set<string> set;
        for(int i = 0 ; i < nums.size(); i++) set.insert(nums[i]);
        solve("", ans, set, n);
        return ans;
    }
};