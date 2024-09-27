class MyCalendarThree {
public:
    map<int, int> line;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        line[startTime]++;
        line[endTime]--;
        int cnt = 0, maxi = 0;

        for(auto &i: line) {
            cnt += i.second;
            maxi = max(maxi, cnt);            
        }
        return maxi;
    } 
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */