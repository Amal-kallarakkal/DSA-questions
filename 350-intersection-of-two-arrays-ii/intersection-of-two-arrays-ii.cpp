class Solution {
public:
    vector<int> maping(vector<int> &nums1, unordered_map<int, int> &mp, vector<int> &nums2) {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) mp[nums1[i]]++;
        for(int i = 0; i < nums2.size(); i++) {
            if(mp.count(nums2[i])) {
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
                if(mp[nums2[i]] == 0) mp.erase(nums2[i]);
            }
        }
        return ans;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> mp;

        return n1>n2 ? maping(nums1, mp, nums2): maping(nums2, mp, nums1);
        
    }
};