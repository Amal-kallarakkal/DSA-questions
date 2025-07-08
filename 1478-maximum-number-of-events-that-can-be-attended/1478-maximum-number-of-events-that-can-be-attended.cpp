class Solution {
public:
    int maxEvents(vector<vector<int>>& item) {
        sort(begin(item), end(item));
        int n = item.size();
        int ans = 0;
        
        int mx_day = 0;
        for(auto& val:item){mx_day = max(mx_day, val[1]);}

        priority_queue<int, vector<int>, greater<>> kitchen;

        int process = 0, day = 1;

        while(day<=mx_day){
            while(process < n and item[process][0] <= day){
                kitchen.push(item[process][1]);

                process++;
            }

            while(!kitchen.empty() and kitchen.top() < day){
                kitchen.pop();
            }

            if(!kitchen.empty()){
                kitchen.pop();
                ans++;
            }

            day++;
        }
        
        return ans;
    }
};