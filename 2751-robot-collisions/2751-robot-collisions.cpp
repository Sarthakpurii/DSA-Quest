class Solution {
public:
    struct robo{
        int hp;
        int pos;
        char dir;
        int idx;
        robo(int h,int p,int i,char d): hp(h),pos(p),idx(i),dir(d){};
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=healths.size();
        vector<robo> robots;
        for(int i=0;i<n;i++){
            robots.push_back(robo(healths[i],positions[i],i,directions[i]));
        }
        sort(robots.begin(),robots.end(),[](robo& r1,robo& r2){return r1.pos<r2.pos;});
        stack<robo> st;
        for(int i=0;i<n;i++){
            bool destroyed=false;
            while(!st.empty() && !destroyed){
                robo r=st.top();
                if(r.dir=='R' && robots[i].dir=='L'){
                    if(r.hp<robots[i].hp){
                        st.pop();
                        robots[i].hp--;
                    }
                    else if(r.hp>robots[i].hp){
                        destroyed=true;
                        st.top().hp--;
                    }
                    else{
                        st.pop();
                        destroyed=true;
                    }
                } else break;
            }
            if(!destroyed) st.push(robots[i]);
        }
        vector<int> ans;
        robots.clear();
        while(!st.empty()){
            robots.push_back(st.top());
            st.pop();
        }
        sort(robots.begin(),robots.end(),[](robo& r1,robo& r2){ return r1.idx<r2.idx;});
        for(int i=0;i<robots.size();i++) ans.push_back(robots[i].hp);
        return ans;
    }
};