class Solution {

    private:
    void Solve(vector<int>& nums,int index, vector<int> output,vector<vector<int>> &ans ){

        //base case
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        Solve(nums,index+1,output,ans);
        //include
        output.push_back(nums[index]);
        Solve(nums,index+1,output,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ios::sync_with_stdio(0);
        vector<vector<int>> ans;
        int index = 0;
        vector<int> output;
        Solve(nums,index,output,ans);
        return ans;
    }
};