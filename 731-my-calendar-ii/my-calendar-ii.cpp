class MyCalendarTwo {
public:
    map<int,int> line;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        line[start]++;
        line[end]--;
        int cnt = 0;

        for(auto &i: line){
            cnt += i.second;
            if(cnt >= 3) {
                line[start]--;
                line[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */