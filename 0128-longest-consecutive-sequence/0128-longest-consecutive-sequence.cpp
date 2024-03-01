class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // nlogn approach as insertion in set takes nlogn on avg
        // if(nums.size()==0) return 0;

        // set<int> sett(nums.begin(),nums.end());
        // int solution=0,temp=0;

        // auto it=sett.begin();
        // for(int n:sett){
        //     advance(it, 1);
        //     if(it!=sett.end() && *it-n==1){
        //         temp++;
        //     }
        //     else{
        //         solution=max(temp+1,solution);
        //         temp=0;
        //     }
        // }
        // return solution;


        // using unordered set O(n) appraoch as avg insertion time is O(n)

        if(nums.size()==0) return 0;

        unordered_set<int> sett(nums.begin(),nums.end());
        int solution=0;
        for(int n:sett){
            if(sett.find(n-1)==sett.end()){
                int temp=1,tempNum=n+1;
                while(sett.find(tempNum)!=sett.end()){
                    temp++;
                    tempNum++;
                }
                solution=max(solution,temp);
            }
        }
        return solution;
    }
};