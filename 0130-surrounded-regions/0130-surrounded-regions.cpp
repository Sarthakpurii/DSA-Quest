class Solution {
public:
    void solve(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<pair<int,int>> st;
        int n=board.size(),m=board[0].size();
        vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') st.push({i,0});
            if(m-1>0 && board[i][m-1]=='O') st.push({i,m-1});
        }
        for(int j=1;j<m-1;j++){
            if(board[0][j]=='O') st.push({0,j});
            if(n-1>0 && board[n-1][j]=='O') st.push({n-1,j});
        }
        cout<<st.size();
        while(!st.empty()){
            auto [x,y]=st.top();
            st.pop();
            board[x][y]='#';
            for(int i=0;i<4;i++){
                int tempx=x+dx[i],tempy=y+dy[i];
                if(tempx>-1 && tempx<n && tempy>-1 && tempy<m && board[tempx][tempy]=='O') st.push({tempx,tempy});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
        // return board;
    }
};