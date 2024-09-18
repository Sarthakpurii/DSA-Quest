struct Node{
    Node* links[26];
    bool flag=false;
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* curr=root;
        for(char c:word){
            if(!curr->links[c-'a']){
                Node* node =new Node();
                curr->links[c-'a']=node;
                curr=node;
            }
            else{
                curr=curr->links[c-'a'];
            }
        }
        curr->flag=true;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(char c:word){
            if(!curr->links[c-'a']) return false;
            else curr=curr->links[c-'a'];
        }
        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(char c:prefix){
            
            if(!curr->links[c-'a']) return false;
            else curr=curr->links[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */