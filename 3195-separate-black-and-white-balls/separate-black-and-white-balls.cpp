using ll = long long;
class Solution {
public:
    long long minimumSteps(string s) {
        ll cnt = 0;
        priority_queue<int> pqmax_0;
        priority_queue<int, vector<int>, greater<int>> pqmin_1;
        for(int i = 0 ; i < s.size(); i++) { 
            if(s[i] == '1') {
                pqmin_1.push(i);
            } else {
                pqmax_0.push(i);
            }
        }
        int top1, top0;
        while(!pqmax_0.empty() && !pqmin_1.empty()) {
            top0 = pqmax_0.top();
            pqmax_0.pop();
            top1 = pqmin_1.top();
            pqmin_1.pop();
            if(top0 < top1) break;
            // swap(s[top0], s[top1]);
            // cout<<"0 max i: "<<top0<<" 1 min i: "<<top1<<endl;
            cnt += top0 - top1;
        }
        // cout<<s;
        return cnt;
    }
};