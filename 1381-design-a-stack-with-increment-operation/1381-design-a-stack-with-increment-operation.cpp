class CustomStack {
public:
    vector<int> st;
    int i=0,n;
    priority_queue<pair<int,int>> pq;
    CustomStack(int maxSize) {
        pq.push({-1,-1});
        n=maxSize;
        st.resize(n);
    }
    
    void push(int x) {
        if(i<n) st[i++]=x;
    }
    
    int pop() {
        if(i==0) return -1;
        i--;
        auto [k,val]=pq.top();
        if(k<i){
            return st[i];
        }
        pq.pop();
        while(!pq.empty() && pq.top().first==k){
            val+=pq.top().second;
            pq.pop();
        }
        pq.push({i-1,val});
        return st[i]+val;
    }
    
    void increment(int k, int val) {
        pq.push({min(k-1,i-1),val});
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */