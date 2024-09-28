class MyCircularDeque {
public:
    vector<int> dq;

    MyCircularDeque(int k) {     
        vector<int> dq(k, -1);   
        this->dq = dq;
    }
    
    bool insertFront(int value) {
        if(dq[dq.size() -1] != -1) return false;
        int j = dq.size() -1;
        if(dq[0] == -1) {
            dq[0] = value;
            return true;
        }

        while(dq[j] == -1 && j > 0) j--;

        for(int i = j + 1 ; i > 0; i-- ) {
            swap(dq[i], dq[i-1]);            
        }
        dq[0] = value;

        return true;
    }
    
    bool insertLast(int value) {
        if(dq[dq.size() -1] != -1) return false;
        int i = 0;
        while(dq[i] != -1) i++;
        dq[i] = value;
        return true;
    }
    
    bool deleteFront() {
        if(dq[0] == -1) return false;
        int j = dq.size() -1;
        while(dq[j] == -1 && j > 0) j--;  
        dq[0] = -1;

        for(int i = 0; i < j ; i++) {
            swap(dq[i], dq[i+1]);
        }
        return true;
    }
    
    bool deleteLast() {
        
        if(dq[0] == -1) return false;
        int j = dq.size() -1;
        while(dq[j] == -1 && j > 0) j--;  
        dq[j] = -1;
        return true;
    }
    
    int getFront() {
        return dq[0];
    }
    
    int getRear() {
        int j = dq.size() -1;
        while(dq[j] == -1 && j > 0) j--;  
        return dq[j];
    }
    
    bool isEmpty() {

        if(dq[0] == -1) return true;
        return false;
    }
    
    bool isFull() {
        if(dq[dq.size() -1] != -1) return true;
        return false;
    }
};

static const int speedup = []() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */