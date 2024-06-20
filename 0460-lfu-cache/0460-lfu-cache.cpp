struct Node{
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;

    Node(int keyy,int vall) : key(keyy),val(vall),prev(nullptr),next(nullptr),freq(1) {}
};
class LFUCache {
private: 
    pair<Node*,Node*> dllCreator(){
        Node* head=new Node(-1,-1);
        Node* tail=head;
        return {head,tail};
    }
public:
    unordered_map<int,pair<Node*,Node*>> freqMap;
    int minFreq=1;
    unordered_map<int,Node*> elemMap;
    int cap;
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(cap==0) return -1;
        if(elemMap.find(key)==elemMap.end()) return -1;
        else{
            Node* temp=elemMap[key];
            if(freqMap[temp->freq].second==temp){
                freqMap[temp->freq].second=freqMap[temp->freq].second->prev;
                freqMap[temp->freq].second->next=nullptr;
                if(freqMap[temp->freq].second==freqMap[temp->freq].first){
                    if(temp->freq==minFreq) minFreq++;
                    freqMap.erase(temp->freq);
                }
            }
            else{
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
            }
            temp->freq++;
            
            if(freqMap.find(temp->freq)==freqMap.end()){
                freqMap[temp->freq]=dllCreator();
            }
            
            if(freqMap[temp->freq].second==freqMap[temp->freq].first){
                freqMap[temp->freq].second=temp;
                temp->prev=freqMap[temp->freq].first;
                freqMap[temp->freq].first->next=temp;
            }
            else{
                temp->next=freqMap[temp->freq].first->next;
                temp->prev=freqMap[temp->freq].first;
                freqMap[temp->freq].first->next->prev=temp;
                freqMap[temp->freq].first->next=temp;
            }
            return temp->val;
        }
    }
    
    void put(int key, int value) {
        if (cap==0) return;
        Node* temp;
        
        if(elemMap.find(key)==elemMap.end()){
            if(cap==elemMap.size()){
                elemMap.erase(freqMap[minFreq].second->key);
                freqMap[minFreq].second=freqMap[minFreq].second->prev;
                freqMap[minFreq].second->next=nullptr;
                if(freqMap[minFreq].second==freqMap[minFreq].first){
                    minFreq=1;
                    freqMap.erase(minFreq);
                }
            }
            temp=new Node(key,value);
            elemMap[key]=temp;
            if(minFreq>temp->freq) minFreq=temp->freq;
            
        }
        else{
            temp=elemMap[key];
            if(freqMap[temp->freq].second==temp){
                freqMap[temp->freq].second=freqMap[temp->freq].second->prev;
                freqMap[temp->freq].second->next=nullptr;
                if(freqMap[temp->freq].second==freqMap[temp->freq].first){
                    if(temp->freq==minFreq) minFreq++;
                    freqMap.erase(temp->freq);
                }
            }
            else{
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
            }
            temp->freq++;
        }
        if(freqMap.find(temp->freq)==freqMap.end()){
            freqMap[temp->freq]=dllCreator();
        }
        if(freqMap[temp->freq].second==freqMap[temp->freq].first){
            freqMap[temp->freq].second=temp;
            temp->prev=freqMap[temp->freq].first;
            freqMap[temp->freq].first->next=temp;
        }
        else{
            temp->next=freqMap[temp->freq].first->next;
            temp->prev=freqMap[temp->freq].first;
            freqMap[temp->freq].first->next->prev=temp;
            freqMap[temp->freq].first->next=temp;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */