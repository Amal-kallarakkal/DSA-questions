class Solution {
public:
    string makeFancyString(string s) {
        string ans, temp;
        for(int i = 0 ; i < s.size() ; i++) {
            temp = "";
            if(i <= s.size() - 3) temp = s.substr(i, 3);
            if((temp[0] == temp[1]) && (temp[2] == temp[1])) {
                // cout<<temp<<endl;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};