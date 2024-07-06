class Solution {
public:
    int passThePillow(int n, int time) {
        
        int i = 1;
        bool r = true;

        while(time--) {
            if(r) i++;
            else i--;

            if(i == n) r = false;
            else if(i == 1) r = true;
        }
        
        return i;
    }
};