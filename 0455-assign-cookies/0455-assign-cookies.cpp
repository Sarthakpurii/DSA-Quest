class Solution {
public:
    int findContentChildren(vector<int>& child, vector<int>& cook) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int c1=child.size(),c2=cook.size(),ans=0;
        if(!c2) return ans;
        sort(child.begin(),child.end());
        sort(cook.begin(),cook.end());
        int i=0,j=0;
        while(i<c1 && j<c2){
        while(j<c2 && child[i]>cook[j]) j++;
            if(j==c2) break;
            ans++;
            i++;
            j++;
        }
        return ans;
    }
};