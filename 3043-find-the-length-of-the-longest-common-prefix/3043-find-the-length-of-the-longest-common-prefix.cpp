struct Node{
    Node* links[10];
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int i){
        string s=to_string(i);
        Node* curr=root;
        for(char c:s){
            if(!curr->links[c-'0']){
                Node* temp=new Node();
                curr->links[c-'0']=temp;
                curr=temp;
            }
            else{
                curr=curr->links[c-'0'];
            }
        }
    }
    int lcp(int i){
        string s=to_string(i);
        Node* curr=root;
        int count=0;
        for(char c:s){
            if(!curr->links[c-'0']) break;
            else{
                curr=curr->links[c-'0'];
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(int i:arr1) t.insert(i);
        int ans=0;
        for(int i:arr2) ans=max(ans,t.lcp(i));
        return ans;
    }
};