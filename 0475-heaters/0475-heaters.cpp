class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int nHouses=houses.size(),nHeaters=heaters.size();
        int low=0,high=max(houses.back()-heaters[0],heaters.back()-houses[0]);
        while(low<=high){
            int mid=low+(high-low)/2;
            bool gettingHeat=turnHeaterOn(houses,mid,heaters);
            if(gettingHeat) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    bool turnHeaterOn(vector<int> houses,int radius,vector<int> heaters){
        int currHeater=0,n=heaters.size(),nHouses=houses.size(),i=0;
        while(i<nHouses){
            if((heaters[currHeater]-radius)<=houses[i] && (heaters[currHeater]+radius)>=houses[i]){
                i++;
                continue;}
            if(currHeater==n-1) break;
            currHeater++;
        }
        if(i==nHouses) return true;
        return false;

    }
};