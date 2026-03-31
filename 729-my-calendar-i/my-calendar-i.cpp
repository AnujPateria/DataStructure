class MyCalendar {
public:


    // vector<int> seg(4*1e9);
    vector<pair<int, int>> calender;
    MyCalendar() {
        
    }

    void query(int st, int en){

    }
    
    bool book(int startTime, int endTime) {
        for(const auto &[s,e] : calender){
            if(startTime < e && s < endTime){
                return false;
            }
        }
        calender.emplace_back(startTime, endTime);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */