class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(k == 1) return true;
        if(nums.size()%k != 0) return false;    

        map<int,int> mp;

        for(int i = 0 ;i < nums.size(); i++) {
            mp[nums[i]]++;
        } 
        int y = -1; 
        int cnt = 0;  
        int maxi = 0; 
        int smallest = -1;
        sort(nums.begin(), nums.end());

        for(int j = 0 ; j  <nums.size(); j++) {
            smallest = nums[j];
            if(mp[nums[j]] <= 0 ) continue;
            // cout<<smallest<<endl;
            for(int i = 0; i < k; i++) {
                if(mp[smallest + i] > 0) mp[smallest + i]--;
                else return false;
                if(mp[smallest + i] <= 0) mp.erase(smallest + i);
            }
        }      
        // cout<<"first:"<<mp.begin()<<endl;
        if(!mp.size()) return false;
        return true;

    }
};