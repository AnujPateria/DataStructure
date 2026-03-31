class MyCalendar {
public:
    set<pair<int, int>> calender;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        const pair<int, int> event(startTime, endTime);
        const auto nextEvent = calender.lower_bound(event);
        if(nextEvent != calender.end() && nextEvent->first < endTime){
            return false;
        }
        if(nextEvent != calender.begin()){
            const auto prevEvent = prev(nextEvent);
            if(prevEvent-> second > startTime){
                return false;
            }
        }
        calender.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */