class Solution {
public:
    string intToBin(string s){
        int temp=stoi(s);
        string ans;
        while(temp){
            ans.push_back((temp%2)?'1':'0');
            temp/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string convertDateToBinary(string date) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        string year=intToBin(date.substr(0,4));
        string month=intToBin(date.substr(5,2));
        string day=intToBin(date.substr(8,2));

        stringstream ans;
        ans<<year.substr(year.find('1'))<<"-";
        ans<<month.substr(month.find('1'))<<"-";
        ans<<day.substr(day.find('1'));
        
        return ans.str();
    }
};