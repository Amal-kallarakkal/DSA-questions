class Solution {
public:
    int solve(string &s, int &x, int &y, string first, string second) {
        stack<char> st;
        string check;
        char top;
        int points = 0;
        
        string temp = "";
        temp.push_back(s[0]);
        st.push(s[0]);
        for(int i = 1; i < s.size(); i++) {
            top = (!st.empty())?st.top() : '1';
            check = string(1,top) + s[i];
            
            if(check == first && !st.empty()) {
                st.pop();
                temp.pop_back();
                points += (first == "ab")?x : y;
            } else {
                st.push(s[i]);
                temp.push_back(s[i]);
            }
        }        
        // cout<<temp<<" , "<<points<<endl;
        stack<char> st2;
        st2.push(temp[0]);
        for(int i = 1; i < temp.size(); i++) {
            top = (!st2.empty())?st2.top() : '1';
            check = string(1,top) + temp[i];
            if(check == second && !st2.empty()) {
                st2.pop();
                points += (second == "ab")?x : y;
            } else {
                st2.push(temp[i]);                
            }
        }
        return points;
    }
    int maximumGain(string s, int x, int y) {
        return max(solve(s, x, y, "ab", "ba"), solve(s, x, y, "ba", "ab"));
    }
};