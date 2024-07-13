class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int> ans;
        map<int, int> ph;
        map<int, char> pd;      
        stack<pair<int, char>> st;
        vector<int> pos = positions;

        for(int i = 0 ; i < positions.size(); i++) {
            ph[positions[i]] = healths[i];
            pd[positions[i]] = directions[i];
        }

        sort(pos.begin(), pos.end());
        st.push({pos[0], pd[pos[0]]});

        for(int i = 1 ; i < pos.size(); i++) {
            if(st.empty()) {
                st.push({pos[i], pd[pos[i]]});
            } else if(st.top().second == 'R' && pd[pos[i]] == 'L') {
                if(ph[st.top().first] > ph[pos[i]]){
                    ph[st.top().first]--;
                    ph[pos[i]] = 0;
                } 
                else if(ph[st.top().first] == ph[pos[i]]) {
                    ph[st.top().first] = 0;
                    ph[pos[i]] = 0;
                    st.pop();
                } else {                    
                    while(!st.empty() && st.top().second == 'R') {
                        if(ph[st.top().first] > ph[pos[i]]){
                            ph[st.top().first]--;
                            ph[pos[i]] = 0;
                            break;
                        } else if(ph[st.top().first] == ph[pos[i]]) {
                            ph[st.top().first] = 0;
                            ph[pos[i]] = 0;
                            st.pop();
                            break;
                        } else {
                            ph[st.top().first] = 0;
                            ph[pos[i]]--;
                            st.pop();
                        }
                    }
                    if(ph[pos[i]]) st.push({pos[i], pd[pos[i]]});
                }
            } else {
                st.push({pos[i], pd[pos[i]]});
            }
        }
        
        for(int i = 0 ; i < positions.size(); i++) {
            if(ph[positions[i]]) ans.push_back(ph[positions[i]]);
        }

        return ans;
    }
};