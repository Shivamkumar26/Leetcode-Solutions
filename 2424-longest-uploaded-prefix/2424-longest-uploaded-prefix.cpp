class LUPrefix {
    vector<int> v;
    int i;
public:
    LUPrefix(int n) {
        v = vector<int> (n+2,0);
        i=1;
    }
    
    void upload(int video) {
        v[video]=1;
	    while(v[i]==1)
			i++;
	}
    
    int longest() {
        return i-1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */