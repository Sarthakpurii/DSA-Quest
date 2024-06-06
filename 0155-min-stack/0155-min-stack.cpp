// TC: O(n), SC: O(n^2)
class MinStack {
public:
    vector<pair<int,int>> st;
    int min=INT_MAX,t=-1;
    MinStack() {
    }
    
    void push(int val) {
        if(val<min) min=val;
        st.push_back({val,min});
        t++;
    }
    
    void pop() {
        st.erase(st.begin()+t);
        t--;
        if(t==-1) min=INT_MAX;
    }
    
    int top() {
        return st[t].first;
    }
    
    int getMin() {
        return st[t].second;
    }
};
// class MinStack {
// public:
//     stack<int> st;
//     MinStack() {
        
//     }
    
//     void push(int val) {
        
//     }
    
//     void pop() {
        
//     }
    
//     int top() {
        
//     }
    
//     int getMin() {
        
//     }
// };
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */