class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char ch : s) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                if(ch == ')') {
                    if(!st.empty() && st.top() == '(') {
                        st.pop();
                    } else return false;
                } 
                else if(ch == '}') {
                    if(!st.empty() && st.top() == '{') {
                        st.pop();
                    } else return false;
                } 
                else if(!st.empty() && ch == ']') {
                    if(st.top() == '[') {
                        st.pop();
                    } else return false;
                } 
            }
        }

        if(st.empty()) return true ;
        else return false;

       
    }
};