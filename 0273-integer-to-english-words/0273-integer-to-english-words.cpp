class Solution {
public:
    void triplet(int& num,string& ans,unordered_map<int,string>& d){
        int n=num/100;
        num=num%100;
        if(n!=0){
            ans+=d.at(n);
            ans+=d.at(100);
        }
        if(num<21 && num) ans+=d.at(num);
        else{
            n=(num/10)*10;
            num%=10;
            if(n) ans+=d.at(n);
            if(num) ans+=d.at(num);
        }
    }
    string numberToWords(int num) {
        
        if(num==0) return "Zero";
        unordered_map<int, string> d = {
        {1, "One "}, {2, "Two "}, {3, "Three "}, {4, "Four "}, {5, "Five "},
        {6, "Six "}, {7, "Seven "}, {8, "Eight "}, {9, "Nine "}, {10, "Ten "},
        {11, "Eleven "}, {12, "Twelve "}, {13, "Thirteen "}, {14, "Fourteen "},
        {15, "Fifteen "}, {16, "Sixteen "}, {17, "Seventeen "}, {18, "Eighteen "},
        {19, "Nineteen "}, {20, "Twenty "}, {30, "Thirty "}, {40, "Forty "},
        {50, "Fifty "}, {60, "Sixty "}, {70, "Seventy "}, {80, "Eighty "},
        {90, "Ninety "}, {100, "Hundred "}, {1000, "Thousand "},
        {1000000, "Million "}, {1000000000, "Billion "}
    };
        string ans;
        for(int i=1000000000;i>0;i/=1000){
            int n=num/i;
            num=num%i;
            if(n){
                triplet(n,ans,d);
                if(i!=1) ans+=d.at(i);
            }
        }
        // triplet(n,ans,d);
        ans.pop_back();
        return ans;
    }
};