class Solution {
public:
    void helper(vector<string>& ans, string& num, string curr, long cv,long pv, int& target, int start){
        if(start==num.size() && cv==target){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<num.size();i++){
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            string temp=num.substr(start,i-start+1);
            long val=stol(temp);
            if(temp[0] == '0' && temp.size() > 1) break;
            if(start==0){
                helper(ans,num,temp,val,val,target,i+1);
                continue;
            }
            helper(ans,num,curr+'+'+temp,cv+val,val,target,i+1);
            helper(ans,num,curr+'-'+temp,cv-val,-val,target,i+1);
            helper(ans,num,curr+'*'+temp,cv-pv+pv*val,val*pv,target,i+1);
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(ans,num,"",0,0,target,0);
        return ans;
    }
};