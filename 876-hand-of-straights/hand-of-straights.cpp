#pragma GCC optimize("OFast")
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios::sync_with_stdio(0);
        int k = groupSize;
        if(k == 1) return true;
        
        if(hand.size()%k != 0) return false;    

        unordered_map<int,int> mp;

        for(int i = 0 ;i < hand.size(); i++) {
            mp[hand[i]]++;
        } 
        
        int smallest = -1;
        sort(hand.begin(), hand.end());

        for(int j = 0 ; j  <hand.size(); j++) {
            smallest = hand[j];
            if(mp[hand[j]] <= 0 ) continue;
            
            for(int i = 0; i < k; i++) {
                if(mp[smallest + i] > 0) mp[smallest + i]--;
                else return false;
                if(mp[smallest + i] <= 0) mp.erase(smallest + i);
            }
        }      
        if(!mp.size()) return false;
        return true;
    }
};