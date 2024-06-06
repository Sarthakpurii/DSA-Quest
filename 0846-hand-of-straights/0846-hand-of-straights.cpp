class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(hand.size()%groupSize!=0) return false;
        map<int,int> countt;
        for(int i:hand)countt[i]++;

        while(!countt.empty()){
            auto it=countt.begin();
            int first=it->first;
            for(int i=0;i<groupSize;i++){
                if(countt[first+i]==0) return false;
                if(--countt[first+i]==0) countt.erase(first+i);
            }
        }
        return true;
        
    }
};