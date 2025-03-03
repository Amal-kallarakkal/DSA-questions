class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l1,l2;
        int same =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) l1.push_back(nums[i]);
            else if(nums[i]==pivot) same++;
            else l2.push_back(nums[i]);
        }
        while(same--) l1.push_back(pivot);
        for(int x: l2) l1.push_back(x);
        return l1;
    }
};