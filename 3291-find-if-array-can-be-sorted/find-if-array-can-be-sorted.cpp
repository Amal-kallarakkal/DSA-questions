#include<bits/stdc++.h>
class Solution {
public:
    
     int DecimalToB(int num) {
        int temp = num;
        
        int cnt = 0; 
        while(temp) {
           int rem = temp%2;
           if(rem) cnt++;
           temp /= 2;
          
        }
         return cnt ;
     }
    
    bool canSortArray(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0 ; i  < n ; i ++) {
            
            mp[nums[i]] = DecimalToB(nums[i]);
        }
        
        for(int i = 0 ; i < n-1 ; i++) {
                
            for(int j = i+1 ; j < n ; j++) {

                    if(nums[i] > nums[j]) {
                        if(mp[nums[i]] == mp[nums[j]]) {
                            int temp = nums[i];  
                            nums[i] = nums[j];
                            nums[j] = temp;

                        } else {
                            return false;
                        }
                    }  
            }
            
            
        }
        
        return true;
        
    }
};