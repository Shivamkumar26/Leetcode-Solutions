class MyCalendarThree {
public:
    // map is storing net events 
    map<int, int> mp;
    int count;
    MyCalendarThree() {
        count = 0;
    }
    
    int book(int start, int end) {
        mp[start]++; //starting an event 
        mp[end]--; // ending an event
        
        int mx = 0;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            mx = mx + i->second; // curr open events
            count = max(count, mx); // max events 
        }
        return count;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */