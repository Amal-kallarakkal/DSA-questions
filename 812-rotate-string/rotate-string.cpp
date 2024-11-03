class Solution {
public:

    void RotateString(string s, string &ans) {
                
        string temp = ans;
        ans = "";
        ans = temp[s.size()-1];
        temp.pop_back();

        ans += temp;

    }
    bool rotateString(string s, string goal) {
       
        int n = s.size();

        if(s == goal) return true;
       
        string ans = s;
        for(int i = 0 ; i < n ; i++) {

            RotateString(s,ans);

            if(ans == goal) return true;

        }
       
        
        return false;
    }
};