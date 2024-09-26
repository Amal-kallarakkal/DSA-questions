class MyCalendar {
public:
    vector<pair<int,int>> date;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        for(int i = 0 ;i < date.size(); i++) {
            if((date[i].first <= start && date[i].second > start) || (date[i].second > end && date[i].first < end) || (date[i].first >= start && date[i].second <= end)) {
                // cout<<endl;
                // cout<<start<<", "<<end<<" are in between"<<date[i].first<<" and "<<date[i].second<<endl;
                return false;
            }
        }

        date.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */