class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int maxi = max(red, blue);
        int mini = min(red, blue);
        int diff = maxi - mini;
        int ans1 = 0;
        int tempred = red;
        int tempb = blue;
        int odd = 1 ;
        int even = 2;
//         red is odd
        while(tempred >= 0 && tempb >= 0) {
            tempred -= odd;
            tempb -= even;
            if(tempred >= 0 && tempb >= 0) ans1 += 2;
            else if(tempred >= 0) ans1 += 1;
            odd += 2;
            even += 2;
            
        }
        // ans1 = odd + even;
        
        tempred = red;
        tempb = blue;
        odd = 1 ;
        even = 2;
        int ans2 = 0;
       while(tempred >= 0 && tempb >= 0) {
            tempb -= odd;
            tempred -= even;
           
            if(tempred >= 0 && tempb >= 0) ans2 += 2;
            else if(tempb >= 0) ans2 += 1;
            odd += 2;
            even += 2;
            
        }
        // ans2 = odd + even;
        // cout<<ans1<<", "<<ans2<<endl;
        
        return max(ans1, ans2);
        
    }
};