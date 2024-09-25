struct Node{
    Node* links[26];
    int c=1;
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* curr=root;
        for(char c:s){
            if(!curr->links[c-'a']){
                Node* temp=new Node();
                curr->links[c-'a']=temp;
                curr=temp;
            }
            else{
                curr=curr->links[c-'a'];
                curr->c++;
            }
        }
    }
    int score(string s){
        Node* curr=root;
        int sc=0;
        for(char c:s){
            curr=curr->links[c-'a'];
            sc+=curr->c;
        }
        return sc;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        int n=words.size();
        vector<int> ans(n);
        for(string s:words){
            t.insert(s);
        }
        for(int i=0;i<n;i++){
            ans[i]=t.score(words[i]);
        }
        return ans;
    }
};