class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<pair<int,int>> q;
        int old=-1,n=image.size(),m=image[0].size();
        if(image[sr][sc]!=color){
            q.push({sr,sc});
            old=image[sr][sc];
        }
        vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            image[x][y]=color;
            for(int i=0;i<4;i++){
                int tempx=x+dx[i],tempy=y+dy[i];
                if(tempx<n && tempx>-1 && tempy<m && tempy>-1 && image[tempx][tempy]==old) q.push({tempx,tempy});
            }
        }
        return image;
    }
};