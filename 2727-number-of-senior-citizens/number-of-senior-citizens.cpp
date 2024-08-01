class Solution {
public:
    int countSeniors(vector<string>& details) {
        int age, cnt = 0;
        for(int i = 0 ; i < details.size(); i ++) {
            age = (details[i][11] - '0')*10 + (details[i][12] - '0');
            if(age > 60) cnt++;
        }
        return cnt;
    }
};