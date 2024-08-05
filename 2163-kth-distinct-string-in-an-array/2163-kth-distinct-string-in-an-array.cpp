class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> set;
        // string ans;

        for(int i = 0 ; i < arr.size(); i++) {
            set[arr[i]]++;
        }
        vector<string> ans;
        int i = set.size() - 1;
        for(int i = 0 ; i < arr.size(); i++) {
            if(set[arr[i]] == 1) ans.push_back(arr[i]);
        }
        if(k > ans.size()) return "";
        
        // for(int i = 0 ; i < ans.size(); i++) cout<<ans[i]<<" ";
        return ans[k-1];
    }
};