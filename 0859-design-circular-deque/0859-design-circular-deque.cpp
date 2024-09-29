class MyCircularDeque {
public:
    vector<int> dq;
    int f=0,b=0,s=0,n;
    MyCircularDeque(int k) {
        dq.resize(k);
        n=k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        dq[f]=value;
        if(f==0) f=n-1;
        else f--;
        s++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(b==n-1) b=0;
        else b++;
        s++;
        dq[b]=value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if(f==n-1) f=0;
        else f++;
        s--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(b==0) b=n-1;
        else b--;
        s--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        int temp=f;
        if(temp==n-1) temp=0;
        else temp++;
        return dq[temp];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return dq[b];
        
    }
    
    bool isEmpty() {
        if(s==0) return true;
        return false;
    }
    
    bool isFull() {
        if(s==n) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */