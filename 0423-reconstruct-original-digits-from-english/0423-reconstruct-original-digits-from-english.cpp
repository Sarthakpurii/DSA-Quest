class Solution {
public:
    string originalDigits(string s) {
        vector<int> mp(10,0);
        for(char c:s){
            if(c=='z') mp[0]++;
            else if(c=='w') mp[2]++;
            else if(c=='x') mp[6]++;
            else if(c=='g') mp[8]++;
            else if(c=='u') mp[4]++;
            else if(c=='s') mp[7]++;
            else if(c=='i') mp[9]++;
            else if(c=='h') mp[3]++;
            else if(c=='f') mp[5]++;
            else if(c=='o') mp[1]++;
        }
        mp[7]=mp[7]-mp[6];
        mp[5]=mp[5]-mp[4];
        mp[9]=mp[9]-mp[8]-mp[6]-mp[5];
        mp[3]=mp[3]-mp[8];
        mp[1]=mp[1]-mp[0]-mp[2]-mp[4];
        stringstream ans;
        for(int i=0;i<10;i++){
            if(mp[i]>0) ans<<string(mp[i],static_cast<char>(i+48));
        }
        return ans.str();
    }
};