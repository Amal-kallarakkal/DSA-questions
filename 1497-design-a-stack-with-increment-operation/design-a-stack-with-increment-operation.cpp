class CustomStack {
public:
    vector<int> stack;
    CustomStack(int maxSize) {
        stack.push_back(maxSize);
    }
    
    void push(int x) {
        if(stack.size() - 1 >= stack[0]) return;
        stack.push_back(x);
    }
    
    int pop() {
        if(stack.size() == 1) return -1;
        // else if(stack.size() == 2) {
        //     stack.pop_back();
        //     return -1;
        // }
        stack.pop_back();
        int top;
        
        return stack[stack.size()];
    }
    
    void increment(int k, int val) {
        if(stack.size() <= k ) {
            for(int i = 1; i < stack.size() ; i++) {
                stack[i] += val;
            }
        } else {
            for(int i = 1; i <= k ; i++) {
                stack[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */