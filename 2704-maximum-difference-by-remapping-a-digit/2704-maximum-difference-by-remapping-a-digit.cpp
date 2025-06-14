class Solution {
public:
    int minMaxDifference(int num) {
     
   
    int temp =num;
        int count =0;
        
        while(temp){
            temp /= 10;
            count++;
        }
        
        int a[count];
        temp =  num;
        int min=9;
        int max =9;
        for(int i=0;i<count;i++){
            a[i] = temp %10;
            temp /= 10;
            
        }
        max = a[count-1];
        
        for(int i=count-1;i>=0;i--){
            if(a[i]<9){ 
                min =a[i];
                break;
            }
        }
        
        
        
        int b[count];
        int c[count];
        for(int i=0;i<count;i++){
            if(a[i]==min) b[i] = 9;
            else b[i] = a[i];
            if(a[i]==max) c[i] =0;
            else c[i] = a[i];
        }
        
        int num1 = 0 ,num2 =0;
        for(int i=0;i<count;i++){
            num1 += b[i]*pow(10,i);
            num2 += c[i]*pow(10,i);
        }
        
        int diff = num1 -num2;
        //cout<<num1<<"  "<<num2;

        return diff;

        
        
    }
};