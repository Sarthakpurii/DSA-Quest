class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    int c=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minheap.empty()) maxheap.push(num);
        else{
            if (minheap.top()<num) minheap.push(num);
            else maxheap.push(num);
        }
        if(minheap.size()>maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
        else if(maxheap.size()>minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size()==maxheap.size()) return (minheap.top()+maxheap.top())/2.0;
        else{
            if(!minheap.empty() && minheap.size()>maxheap.size()) return minheap.top();
            return maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */