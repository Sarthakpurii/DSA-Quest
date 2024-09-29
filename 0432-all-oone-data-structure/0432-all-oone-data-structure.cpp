struct node{
    string s;
    int freq=1;
    node* prev;
    node* next;
    node(string str){s=str;};
};
class AllOne {
public:
    unordered_map<string, node*> elemmp;
    unordered_map<int,pair<node*,node*>> freqmp;
    int minfreq=-1, maxfreq=-1;
    AllOne() {
        
    }
    
    void inc(string key) {
        
        if(elemmp.find(key)==elemmp.end()){
            node* temp=new node(key);
            elemmp[key]=temp;
            temp->next=freqmp[1].first;
            if(freqmp[1].first) freqmp[1].first->prev=temp;
            if(maxfreq==-1) maxfreq=1;
            if(!freqmp[1].second){
                freqmp[1].second=temp;
            }
            freqmp[1].first=temp;
            minfreq=1;
        }
        else{
            node* temp=elemmp[key],*prevfreqhead=freqmp[temp->freq].first,* prevfreqtail=freqmp[temp->freq].second;
            if(prevfreqhead==prevfreqtail){
                if(minfreq==temp->freq) minfreq++;
                freqmp.erase(temp->freq);
            } 
            else if(prevfreqhead==temp){
                freqmp[temp->freq].first=prevfreqhead->next;
                freqmp[temp->freq].first->prev=nullptr;
            }
            else if(prevfreqtail==temp){
                freqmp[temp->freq].second=prevfreqtail->prev;
                freqmp[temp->freq].second->next=nullptr;
            }
            else{
                temp->next->prev=temp->prev;
                temp->prev->next=temp->next;
            }
            temp->next=nullptr;
            temp->prev=nullptr;
            temp->freq++;
            if(maxfreq<temp->freq) maxfreq=temp->freq;
            if(freqmp.find(temp->freq)==freqmp.end()){
                freqmp[temp->freq].first=temp;
                freqmp[temp->freq].second=temp;
            }
            else{
                temp->next=freqmp[temp->freq].first;
                if(freqmp[temp->freq].first) freqmp[temp->freq].first->prev=temp;
                freqmp[temp->freq].first=temp;
            }
        }
    }
    
    void dec(string key) {
        node* temp=elemmp[key],*prevfreqhead=freqmp[temp->freq].first,* prevfreqtail=freqmp[temp->freq].second;
        if(prevfreqhead==prevfreqtail){
            if(temp->freq==1){
                if(maxfreq==1){
                    maxfreq=-1;
                    minfreq=-1;
                }
            }
            if(temp->freq==minfreq){
                for(int i=minfreq+1;i<=maxfreq;i++){
                    if(freqmp.find(i)!=freqmp.end()){
                        minfreq=i;
                        break;
                    }
                }
            }
            if(maxfreq==temp->freq) maxfreq--;
            freqmp.erase(temp->freq);
        }
        else if(prevfreqhead==temp){
            freqmp[temp->freq].first=prevfreqhead->next;
            freqmp[temp->freq].first->prev=nullptr;
        }
        else if(prevfreqtail==temp){
            freqmp[temp->freq].second=prevfreqtail->prev;
            freqmp[temp->freq].second->next=nullptr;
        }
        else{
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
        }
        temp->next=nullptr;
        temp->prev=nullptr;
        temp->freq--;
        if(temp->freq==0){
            elemmp.erase(temp->s);
        }
        else if(freqmp.find(temp->freq)==freqmp.end()) {
            if(minfreq>temp->freq) minfreq=temp->freq;
            freqmp[temp->freq].first=temp;
            freqmp[temp->freq].second=temp;
        }
        else{
            if(minfreq>temp->freq) minfreq=temp->freq;
            temp->next=freqmp[temp->freq].first;
            if(freqmp[temp->freq].first) freqmp[temp->freq].first->prev=temp;
            freqmp[temp->freq].first=temp;
        }
    }
    
    string getMaxKey() {
        if(maxfreq==-1) return "";
        return freqmp[maxfreq].second->s;
    }
    
    string getMinKey() {
        if(minfreq==-1) return "";
        return freqmp[minfreq].first->s;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */