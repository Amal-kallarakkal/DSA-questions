class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int n1 =  str1.length();
        int n2 =  str2.length();
        int count = 0, i = 0 , j = 0, diff;
        
        while(i < n1 && j < n2) {
            diff = int(str2[j]) - int(str1[i]);
            // cout<<diff<<" : "<<str2[i]<<" "<<str1[j]<<endl;
            if(diff == 1||diff == 0 || diff == -25) {
                count++;
                j++;
                // break;
            }
            i++;
        }

        if(count>=n2) {
            return true;
        }
        return false;
        
    }
};