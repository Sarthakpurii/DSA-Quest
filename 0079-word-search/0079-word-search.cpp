class Solution {
public:
    vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
    bool helper(vector<vector<char>>& board, string& word,int idx,int x,int y){
        if(idx==word.size()) return true;

        int n=board.size(),m=board[0].size();
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>-1 && ny>-1 && nx<n && ny<m && board[nx][ny]==word[idx]){
                board[nx][ny]='0';
                if(helper(board,word,idx+1,nx,ny)) return true;
                board[nx][ny]=word[idx];
            }
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char,int> boardmp,wordmp;
        int n=word.size();
        for(auto i:board) for(auto j:i) boardmp[j]++;
        for(char i:word) wordmp[i]++;
        for(auto i:wordmp){
            if(i.second>boardmp[i.first]) return false;
        }
        if(boardmp[word[0]]>boardmp[n-1]) reverse(word.begin(),word.end());
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    board[i][j]='0';
                    if(helper(board,word,1,i,j)) return true;
                    board[i][j]=word[0];
                }
            }
        }
        return false;
    }
};