class Solution {
public:

    bool isPalindrome(int start, int end, string s){

        while(start<=end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void parti(int ind, vector<string> output, vector<vector<string>> &ans, string s){
        
        if(ind == s.size()){
            ans.push_back(output);
        }

        for(int i=ind; i<s.size(); i++){

            if(isPalindrome(ind, i, s)){
                output.push_back(s.substr(ind, i-ind+1));
                parti(i+1, output, ans, s);

                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;

        parti(0, output, ans, s);

        return ans;
    }
};