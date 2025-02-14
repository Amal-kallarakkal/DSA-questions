class ProductOfNumbers {
public:
    vector<int> nums;
    int n , prod;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
        // for(int i: nums) cout<<i<<" ";
        // cout<<endl;
    }
    
    int getProduct(int k) {
        n = nums.size() - 1, prod = 1;
        for(int i = n ; i > n - k; i--) {
            prod *= nums[i];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */