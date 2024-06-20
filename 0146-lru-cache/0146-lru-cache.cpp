// class LRUCache {
// public:
//     deque<pair<int,int>> dq;
//     int cap;
//     LRUCache(int capacity) {
//         cap=capacity;
//     }
    
//     int get(int key) {
//         for(int i=0;i<dq.size();i++){
//             if (dq[i].first==key){
//                 dq.push_back({dq[i].first,dq[i].second});
//                 dq.erase(dq.begin()+i);
//                 return dq.back().second;
//             };
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         for(int i=0;i<dq.size();i++){
//             if (dq[i].first==key){
//                 dq.push_back({dq[i].first,value});
//                 dq.erase(dq.begin()+i);
//                 if(dq.size()>cap) {dq.pop_front();}
//                 return;
//             }
//         }
//         if(dq.size()==cap) {dq.pop_front();}
//         dq.push_back({key,value});
        
//     }
// };
struct Node{
    Node* next;
    Node* prev;
    int key;
    int val;

    Node(int keyy,int value) : key(keyy),next(nullptr),val(value),prev(nullptr) {}
};
class LRUCache {
public:
    int cap;
    Node *head=new Node(-1,-1);
    Node *tail=head;
    unordered_map<int,Node*> nodeMap;
    
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(nodeMap.find(key)==nodeMap.end()) return -1;
        else{
            Node* temp;
            if(nodeMap[key]==tail){
                tail=tail->prev;
                tail->next=nullptr;
                temp= nodeMap[key];
            }
            else{
                temp= nodeMap[key];
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
            if(head==tail) tail=temp;
            temp->next=head->next;
            temp->prev=head;
            if(head->next) head->next->prev=temp;
            head->next=temp;
            return temp->val;
        }
        
    }
    
    void put(int key, int value) {
        // Node* temp=new Node(key,value);
        Node* temp;
        if (nodeMap.find(key)!=nodeMap.end()){
            if(nodeMap[key]==tail){
                tail=tail->prev;
                tail->next=nullptr;
                temp= nodeMap[key];
            }
            else{
                temp= nodeMap[key];
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
            temp->val=value;
        }
        else{
            temp=new Node(key,value);
            if(cap==nodeMap.size()){
                nodeMap.erase(tail->key);
                tail=tail->prev;
                tail->next=nullptr;
            }
            nodeMap[key]=temp;
        }
        if(head==tail) tail=temp;
        temp->next=head->next;
        temp->prev=head;
        if(head->next) head->next->prev=temp;
        head->next=temp;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */