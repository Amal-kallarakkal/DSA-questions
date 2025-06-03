class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int sum = 0, top;
        queue<int> q;
        set<int> closed;
        int ini = initialBoxes.size();
        
        for(int i = 0; i < ini; i++) {
            q.push(initialBoxes[i]);
        }

        while(!q.empty()) {
            top = q.front();
            q.pop();

            if(status[top]) {
                sum += candies[top];
                if(containedBoxes[top].size()) {
                    for(int i : containedBoxes[top]) {
                        q.push(i);
                    }
                } 
                if(keys[top].size()) {
                    for(int i : keys[top]) {
                        if(closed.count(i)) {
                            q.push(i);
                            closed.erase(i);
                        }
                        status[i] = 1;
                    }
                }
            } else closed.insert(top);
        }

        return sum;
    }
};