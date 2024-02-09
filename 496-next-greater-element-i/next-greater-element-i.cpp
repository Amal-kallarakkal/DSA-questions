class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int>mp;
        int j = 0;
        for(int i= 0; i < nums2.size(); i++) {
            
            mp[nums2[i]] = i;
                
        }

        for(auto x: mp) {
            cout<<x.first<<": "<<x.second<<endl;
        }

        j = 0;
        int i = 0; //nums1 iterator
        while(i < nums1.size()) {
            j = mp[nums1[i]] + 1;
            int maxi = nums1[i];
            int a = -1;
            while(j < nums2.size())  {
                if(maxi < nums2[j]) {
                    a = nums2[j];
                    break;
                }
                j++;
            }
            i++;
            if(i < nums1.size())j =  mp[nums1[i]];
            ans.push_back(a);
        }

        return ans;
    }
};