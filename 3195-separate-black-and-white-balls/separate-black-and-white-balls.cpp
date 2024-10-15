using ll = long long;
class Solution {
public:
    long long minimumSteps(string s) {
        
        ll cnt = 0;
        int j = s.size() - 1, i = 0;
        while(i < j && j) { 
            while(s[i] != '1' && i < s.size()) i++; 
            
            while(s[j] != '0' && j) j--;

            if(i < j) cnt += j -i;
            else break;
            i++; 
            j--;
        }
        
        return cnt;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


