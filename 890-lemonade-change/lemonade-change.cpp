class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        if(bills[0] != 5) return false;
        else mp[5]++;

        for(int i = 1 ; i < bills.size(); i++ ) {
        // cout<<mp[5]<<" , "<<mp[10]<<", "<<mp[20]<<endl;

            if(bills[i] == 10) {
                mp[5]--;
                mp[10]++;
            } else if(bills[i] == 20) {
                if(mp[10] > 0) {
                    mp[10]--;
                    mp[20]++;
                    if(mp[5] > 0) mp[5]--;
                    else return false;
                }
                else if(mp[5] >= 3) {
                    mp[5] -= 3;
                    mp[20]++;
                } else {
                    return false;
                }
            }
            else {
                mp[5]++;
            }
        }

        return true;
    }
};