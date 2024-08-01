class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n  = details.size();
        int age, cnt = 0;
        for(int i = 0 ; i < n ; i ++) {
            age = 0;
            age = (details[i][11] - '0')*10 + (details[i][12] - '0');
            // cout<<age<<endl;
            if(age > 60) cnt++;
        }
        return cnt;
    }
};