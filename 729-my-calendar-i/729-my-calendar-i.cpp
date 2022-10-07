class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int c=0;
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            c += i->second;
            if(c>=2) {
                mp[start]--;
                mp[end]++;
                return 0;
            }
        }
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */