class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<string> q;
        unordered_set<string> wordset(words.begin(),words.end());
        wordset.erase(begin);
        q.push(begin);
        int ans=0,wsize=words[0].size();
        while(!q.empty()){
            int s=q.size();
            ans++;
            for(int i=0;i<s;i++){
                string s=q.front();
                q.pop();
                for(int j=0;j<wsize;j++){
                    char org=s[j];
                    for(int k='a';k<='z';k++){
                        s[j]=char(k);
                        if(wordset.find(s)!=wordset.end()){
                            // cout<<s<<endl;
                            if(s==end) return ans+1;
                            wordset.erase(s);
                            q.push(s);
                        }
                    }
                    s[j]=org;
                }
            }
        }
        return 0;
    }
};