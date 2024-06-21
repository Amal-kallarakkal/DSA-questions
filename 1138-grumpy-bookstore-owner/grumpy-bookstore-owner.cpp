#pragma GCC optimize("OFast")
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios::sync_with_stdio(0);
        int ans = 0, sum = 0;
        int st = 0, end;
        int i = 0;

        while(i < customers.size()) {
                if(!grumpy[i]) sum += customers[i];
                i++;    
        }

        while(st < minutes ) {
                if(grumpy[st]) sum += customers[st];
                st++;
        }
        st = 0;
        while(st < customers.size() - minutes + 1) {
            
            end = st + minutes;
            
            ans = max(sum, ans);
            
            if(end >= grumpy.size()) break;
            if(grumpy[end]) sum += customers[end];
            
            if(grumpy[st]) sum -= customers[st];
            st++;            
        }
        
        return ans;
    }
};