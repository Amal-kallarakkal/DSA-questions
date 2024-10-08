class Solution {
public:
    int minSwaps(string s) {
        int no = 0, nc = 0, i = 0, j = s.size() - 1, ans = 0;

        while(i < s.size()) {
            if(s[i] == ']') nc++;
            else if(s[i] == '[') no++;
            
            if(nc > no) {
                ans++;
                no++;
                nc--;
            }
            i++;
        }

        return ans;
        
    }
};