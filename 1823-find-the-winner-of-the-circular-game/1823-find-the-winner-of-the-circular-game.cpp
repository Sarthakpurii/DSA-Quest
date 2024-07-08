class Solution {
public:
    int findTheWinner(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int win=0;
        for(int i=1;i<=n;i++){
            win=(win+k)%i;
        }
        return win+1;
    }
};

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         queue<int> q;
//         for(int i=1;i<=n;i++){
//             q.push(i);
//         }
//         while(q.size()!=1){
//             for(int i=1;i<k;i++){
//                 q.push(q.front());
//                 q.pop();
//             }
//             q.pop();
//         }
//         return q.front();
//     }
// };