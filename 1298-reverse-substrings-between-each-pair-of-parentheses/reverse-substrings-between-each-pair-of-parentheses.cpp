class Solution {
public:
   
    string reverseParentheses(string s) {
        stack<int> st;
        int from;
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')') {
                from = st.top();
                st.pop();
                reverse(s.begin() + from + 1, s.begin() + i);
            }
        }
        string ans = "";
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] != '(' && s[i] != ')') ans.push_back(s[i]);
        }
        return ans;
    }
};