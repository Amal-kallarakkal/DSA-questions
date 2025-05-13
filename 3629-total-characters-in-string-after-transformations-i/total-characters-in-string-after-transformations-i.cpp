int m = pow(10, 9) + 7;
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp1(26);
        int sum = 0;
        for(int i = 0 ; i < s.size(); i++) {
            mp1[s[i] - 'a']++;
        }
        while(t--) {
            vector<int> mp2(26);
            for(int i = 0 ;i < 26; i++) {
                if(i < 25) mp2[i+1] = (mp2[i+1]%m + mp1[i]%m)%m;
                else {
                    mp2[0] = (mp2[0]%m + mp1[i]%m)%m;
                    mp2[1] = (mp2[1]%m + mp1[i]%m)%m;
                }
            }
            mp1 = mp2;
        }
        for(int i = 0 ; i < 26; i++) {
            sum = (sum + mp1[i])%m;
        }
        return sum;
    }
};