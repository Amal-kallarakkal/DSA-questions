class Solution {
public:
    int minLength(string s) {
        int i = 1;
        stack<char> st;
        st.push(s[0]);
        while(i < s.size()) {    
            if(st.empty()) {
                st.push(s[i]);
            } else if(st.top() == 'A' && s[i] == 'B') {
                st.pop();
            } else if(st.top() == 'C' && s[i] == 'D') {
                st.pop();
            } else {
                st.push(s[i]);
            }
            i++;
        }

        return st.size();
    }
};

// const static int speedup = []() {
//     ios::sync_with_stdio();
//     cin.tie(NULL);
//     cout.tie(NULL);
//     return 0;
// }();
