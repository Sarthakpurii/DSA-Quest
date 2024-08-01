class Solution {
private:
    void dfs(vector<vector<string>>& ans,vector<string>& curr,int currlevel,vector<pair<string,int>> levels,int curridx,string str){
        if(str==levels[0].first){
            curr.push_back(str);
            ans.push_back(curr);
            curr.pop_back();
            return;
        }

        for(;curridx>-1 && levels[curridx].second==currlevel;curridx--){}
        
        for(;curridx>-1 && levels[curridx].second==currlevel-1;curridx--){
            if(possible(str,levels[curridx].first)){
                curr.push_back(str);
                dfs(ans,curr,currlevel-1,levels,curridx,levels[curridx].first);
                curr.pop_back();
            }
        }
        
    }
    bool possible(string s,string v){
        int diff=0;
        for(int i=0;i<s.size();i++){
            diff+=(s[i]!=v[i]);
            if(diff>1) return false;
        }
        return true;
    }
    
public:
    vector<vector<string>> findLadders(string begin, string end, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<string>> ans;
        unordered_set<string> wordset(words.begin(),words.end());
        if(wordset.find(end)==wordset.end()) return ans;
        queue<string> q;
        vector<pair<string,int>> levels;
        bool flag=false;

        wordset.erase(begin);
        q.push(begin);
        int cnt=1; //shortest path length
        levels.push_back({begin,1});

        while(!q.empty() && !flag){
            cnt++;
            int s=q.size();
            for(int i=0;i<s;i++){
                string s=q.front();
                q.pop();
                for(int j=0;j<s.size();j++){
                    char org=s[j];
                    for(char k='a';k<='z';k++){
                        if(k==org) continue;
                        s[j]=k;
                        if(wordset.find(s)!=wordset.end()){
                            levels.push_back({s,cnt});
                            if(s==end){
                                flag=true;
                                break;
                            }
                            q.push(s);
                            wordset.erase(s);
                        }
                    }
                    if(flag) break;
                    s[j]=org;
                }
                if(flag) break;
            }
        }
        if(levels.back().first!=end) return ans;

        // for(auto i:levels){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        vector<string> curr;

        dfs(ans,curr,levels.back().second,levels,levels.size()-1,end);
        for(auto& i:ans) reverse(i.begin(),i.end());
        
        return ans;
    }
};