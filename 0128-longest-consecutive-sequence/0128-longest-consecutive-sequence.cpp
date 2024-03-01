class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        
        if(nums.size()==0) return 0;

        set<int> sett(nums.begin(),nums.end());
        int solution=0,temp=0;

        auto it=sett.begin();
        for(int n:sett){
            advance(it, 1);
            if(it!=sett.end() && *it-n==1){
                temp++;
            }
            else{
                solution=max(temp+1,solution);
                temp=0;
            }
        }
        return solution;
    }
};