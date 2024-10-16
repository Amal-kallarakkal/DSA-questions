class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        pair<int, char> top1, top2;
        int i , j;
        while(pq.size() > 1) {
            top1 = pq.top();
            pq.pop();
            if(pq.size()) top2 = pq.top();
            pq.pop();

            // cout<<"top1: "<<top1.first<<" , "<<top1.second<<endl;
            // cout<<"top2: "<<top2.first<<" , "<<top2.second<<endl;

            i = 0;
            j = 0;
            if(s.size() && s[s.size() - 1] == top1.second) {
                while(j < top2.first && j < 1) {
                    s += top2.second;
                    j++;
                }
            } else {
                while(i < top1.first && i < 2) {
                    s += top1.second;
                    i++;
                }
            } 
            if(top1.first - i > 0) pq.push({top1.first - i, top1.second});
            if(top2.first - j > 0) pq.push({top2.first - j, top2.second });
        }
        if(pq.size()) {
            if(s.size()) {
                if(s[s.size() - 1] == pq.top().second) return s;
            }
            top1 = pq.top();
            i = 0;
            // cout<<top1.first<<" , "<<top1.second<<endl;
            while( i < 2 && i < top1.first) {
                s += top1.second;
                i++;
            }
        }
        return s;
    }
};