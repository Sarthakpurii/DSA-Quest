class Solution {
public:
    int mod=1e9+7;
    struct node{
        long elem;
        int idx;
        node(long a,int b): elem(a),idx(b){}
    };
    struct cust{
        bool operator()(node& n1, node& n2){
            if (n1.elem==n2.elem){
                return n1.idx>n2.idx;
            }
            return n1.elem>n2.elem;
        }
    };
    long pow(long base,int exp){
        long res=1;
        while(exp>0){
            if(exp&1) res=res*base%mod;
            base=base*base%mod;
            exp/=2;
        }
        return res;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multi) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(multi==1) return nums;
        priority_queue<node,vector<node>,cust> pq;
        int n=nums.size(),c=0;
        for(int i=0;i<n;i++){
            pq.push(node(nums[i],i));
        }
        vector<bool> mark(n,false);
        while(c!=n && k>0){
            node temp=pq.top();
            pq.pop();
            if(!mark[temp.idx]){
                mark[temp.idx]=true;
                c++;
            }
            temp.elem=temp.elem*multi;
            pq.push(node(temp.elem,temp.idx));
            k--;
        }
        int exp=k/n,powmulti=pow(multi,exp)%mod,remain=k%n;
        while(!pq.empty()){
            node temp=pq.top();
            pq.pop();
            temp.elem%=mod;
            if(remain>0){
                temp.elem=temp.elem*multi%mod;
                remain--;
            }
            nums[temp.idx]=temp.elem*powmulti%mod;
        }
        return nums;
    }
};