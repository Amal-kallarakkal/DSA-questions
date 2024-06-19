using ll = long long;
class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        int sum = 0;
        int rem = 0;
        while(!st.count(n)) {
            st.insert(n);
            while(n) {
                rem = n%10;
                // cout<<rem<<endl;
                sum += rem*rem;
                n /= 10;
            }
            if(sum == 1) return true;
            
            n = sum;
            sum = 0;
        }
        return false;
    }
};