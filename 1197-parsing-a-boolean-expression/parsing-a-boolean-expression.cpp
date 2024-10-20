class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> op;
        stack<char> st;
        char top;
        int res = -1, ans;
        char num ;
        for(int i = 0 ; i < s.size(); i++) {
            if(s[i] == '!' || s[i] == '&' || s[i] == '|' ) op.push(s[i]);
            else if(s[i] == ',') continue;
            else {
                if(s[i] == ')') {
                    top = op.top();
                    op.pop();
                    ans = -1;
                    while(st.top() != '(') {                        
                        num = st.top();
                        st.pop();
                        if(num == 't') {
                            if(ans == - 1) ans = 1;                            
                            else if(top == '|') ans = ans|1;
                            else if(top == '&') ans = ans&1;
                        } else {
                            if(ans == - 1) ans = 0;                            
                            else if(top == '|') ans = ans|0;
                            else if(top == '&') ans = ans&0;
                        }
                        if(top == '!' && ans != -1) ans = !ans;
                    }
                    if(st.size()) st.pop();
                    // cout<<ans<<" at i = "<<i<<" op: "<<top<<endl;
                    if(ans) st.push('t');
                    else st.push('f');
                } else st.push(s[i]);
            }
        }
        
        return ans;
    }
};