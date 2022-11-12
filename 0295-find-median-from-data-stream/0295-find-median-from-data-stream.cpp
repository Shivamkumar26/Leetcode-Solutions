class MedianFinder {
public:
    
    //2 heaps storing in sorted order half half elements 
    //no. of ele in increasing  >= no. of ele in decreasing 
    
    priority_queue<int> decreasing;
    priority_queue<int, vector<int>, greater<int>> increasing;
    bool isEven = true;
    MedianFinder() {
    }
    
    void addNum(int num) {
        isEven = !isEven;
        if(isEven) {
            increasing.push(num);
            decreasing.push(increasing.top());
            increasing.pop();
        }
        else {
            decreasing.push(num);
            increasing.push(decreasing.top());
            decreasing.pop();
        }
    }
    
    double findMedian() {
        if(isEven) return (double)(decreasing.top() + increasing.top())/2.0;
        return increasing.top();
    }
};

/**
    void addNum(int num) {
        evn =!evn;
        if(!evn){
        decreasing.push(num);
        increasing.push(decreasing.top());
        decreasing.pop();}
        else{
              increasing.push(num);
              decreasing.push(increasing.top());
              increasing.pop();
        }
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */