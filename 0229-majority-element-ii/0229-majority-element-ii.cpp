class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // unordered_map<int,int> table;
        // for(int i=0;i<nums.size();i++){
        //     table[nums[i]]++;
        // }
        // vector<int> sol;
        // for(auto it: table){
        //     if (it.second>nums.size()/3) sol.push_back(it.first);
        // }
        // return sol;

        int c1=0,c2=0,cand1,cand2;
        vector<int> solution;

        for(int i=0;i<nums.size();i++){
            if(c1==0 && cand2!=nums[i]){
                cand1=nums[i];
                c1++;
            }
            else if(c2==0 && cand1!=nums[i]){
                cand2=nums[i];
                c2++;
            }
            else if (cand1==nums[i]) c1++;
            else if (cand2==nums[i]) c2++;
            else{
                c1--;
                c2--;
            }
        }

        c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(cand1==nums[i]) c1++;
            else if (cand2==nums[i]) c2++;
        }
        
        if(c1>nums.size()/3) solution.push_back(cand1);
        if(c2>nums.size()/3) solution.push_back(cand2);
        return solution;
        
    }
};