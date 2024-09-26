class Solution {
public:
    vector<int> memo(int i,int j,string exp,unordered_map<string,vector<int>>& dp){
        string key=to_string(i)+'-'+to_string(j);
        if(dp.find(key)!=dp.end()) return dp[key];
        if(i==j || i==j-1) return dp[key]=vector<int>{stoi(exp.substr(i,j-i+1))};
        vector<int> v;
        for(int k=i+1;k<=j-1;k++){
            if(isdigit(exp[k])) continue;
            char c=exp[k];
            vector<int> l=memo(i,k-1,exp,dp);
            vector<int> r=memo(k+1,j,exp,dp);
            for(int elem1:l){
                for(int elem2:r){
                    if(c=='+') v.push_back(elem1+elem2);
                    else if(c=='-') v.push_back(elem1-elem2);
                    else v.push_back(elem1*elem2);
                }
            }
        }
        return dp[key]=v;
    }
    // 2+2+2+2+2+2
    vector<int> diffWaysToCompute(string exp) {
        unordered_map<string,vector<int>> dp;
        int n=exp.size();
        return memo(0,n-1,exp,dp);
        // for(int i:dp["0-4"]) cout<<i<<" ";

        // return dp["0-4"];
    }
};