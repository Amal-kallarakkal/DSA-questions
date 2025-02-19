class Solution {
public:
    void solve(int &n, int &k, vector<string> &nums, string temp) {
        char current ;
        if(temp.size() >= n ) {
            // cout<<temp<<endl;
            nums.push_back(temp);
            return;
        }
        if(temp == "") {
            solve(n, k, nums, temp + 'a');
            solve(n, k, nums, temp + 'b');
            solve(n, k, nums, temp + 'c');
        } else {
            current = temp[temp.size() - 1];
            if(current == 'a') {
                solve(n, k, nums, temp + 'b');
                solve(n, k, nums, temp + 'c');
            } else if(current == 'b') {
                solve(n, k, nums, temp + 'a');
                solve(n, k, nums, temp + 'c');
            } else {
                solve(n, k, nums, temp + 'b');
                solve(n, k, nums, temp + 'a');
            }   
        }
        
    } 
    string getHappyString(int n, int k) {
        vector<string> nums;
        solve(n, k, nums,"");
        sort(nums.begin(), nums.end());
        // for(string x: nums) cout<<x<<endl;
        return (k <= nums.size()) ? nums[k - 1] : "";
    }
};