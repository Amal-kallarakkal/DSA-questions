class NumberContainers {
public:
    unordered_map<int, int> indexmp;
    unordered_map<int, set<int>> numbermp;

    NumberContainers() {
    }
    
    void change(int index, int number) {
         if(indexmp[index]) numbermp[indexmp[index]].erase(index);  
            
        indexmp[index] = number;
        numbermp[number].insert(index);

    }
    
    int find(int number) {
        for(auto &x : numbermp ) {
            if(x.first == number){
                for(auto &y : x.second) return y;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */