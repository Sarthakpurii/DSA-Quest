// TC: O(n), SC: O(n^2)
// class MinStack {
// public:
//     vector<pair<int,int>> st;
//     int min=INT_MAX,t=-1;
//     MinStack() {
//     }
    
//     void push(int val) {
//         if(val<min) min=val;
//         st.push_back({val,min});
//         t++;
//     }
    
//     void pop() {
//         st.erase(st.begin()+t);
//         t--;
//         if(t==-1) min=INT_MAX;
//         else min=st[t].second;
//     }
//     int top() {
//         return st[t].first;
//     }
    
//     int getMin() {
//         return st[t].second;
//     }
// };

// TC: O(n), SC: O(n)
class MinStack {
public:
    vector<int> st;
    int topp=-1,min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(topp==-1){
            min=val;
            st.push_back(val);
            topp++;
        }
        else{
            if(min>val){
                st.push_back(2*val-min);
                min=val;
            }
            else{
                st.push_back(val);
            }
            topp++;
        }

    }
    
    void pop() {
        if(min>st[topp]){
            min=2*min-st[topp];   
        }
        st.erase(st.begin()+topp);
        topp--;
    }
    
    int top() {
        if(min>st[topp]) return min;
        return st[topp];
    }
    
    int getMin() {
        return min;
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
