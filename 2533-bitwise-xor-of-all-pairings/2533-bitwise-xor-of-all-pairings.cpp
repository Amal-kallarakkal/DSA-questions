class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, ans1 = 0, ans2 = 0, n1 = nums1.size(), n2 = nums2.size(), a = 0, b = 0;
        
        for(int i = 0; i < n1; i++) ans1 ^= nums1[i];
        for(int i = 0; i < n2; i++) ans2 ^= nums2[i];
        if(n1%2 == 0) ans2 = 0;
        if(n2%2 == 0) ans1 = 0;
        cout<<ans1<<", "<<ans2<<endl;
        ans = ans1^ans2;
        return ans;
    }
};