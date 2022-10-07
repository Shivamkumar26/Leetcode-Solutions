class MyCalendarTwo {
public:
    map<int, int> mp;
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int curr_count = 0;
        for(auto i = mp.begin(); i != mp.end(); i++) {
            curr_count += i->second;
            if(curr_count >= 3) {
                mp[start]--;
                mp[end]++;
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