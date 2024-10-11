class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
    }


    bool book(int start, int end) {
        auto iter=st.upper_bound({start,end});
        if(iter!=st.end() && iter->second<end) return false;
        st.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
