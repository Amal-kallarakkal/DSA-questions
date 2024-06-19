class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for(int i = 0 ; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }

        for(auto x: mp) {
            pq.push({x.second, x.first});
        }
        pair<int, char> top;
        int cnt = 0;
        int interval = 0;
        stack<pair<int, char>> st;
        int i = 0;
        while(!pq.empty()) {            
            cnt = 0;
            while(cnt < n + 1) { 
                
                if(!pq.empty()) {
                    top = pq.top();
                    pq.pop();
                    // cout<<top.first<<" , "<<top.first - 1<< " : "<<top.second<<endl;
                    if(top.first > 1) st.push({top.first - 1, top.second});
                    i++; 
                }
                if(i >= tasks.size())  break;
                // cout<<top.first<<" : "<<top.second<<endl;
                interval++;
                cnt++; 
                              
            }
            while(!st.empty()) {
                pq.push(st.top());
                // cout<<st.top().first<<" "<<st.top().second<<endl;
                st.pop();
            }
            
        }

        return interval +1;

    }

};