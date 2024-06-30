class Solution {
public:
    int triangleCreator(int red,int blue,bool con){
        if(con) swap(red,blue);
        int level=0,req=1,turn=1; //turn 1 for red
        while(req<=blue || req<=red){
            if((turn && red<req) || (!turn && blue<req)){
                return level;
            }
            else if(turn) red-=req;
            else if (!turn) blue-=req;
            level++;
            turn=!turn;
            req++;
        }
        return level;
    }
    int maxHeightOfTriangle(int red, int blue) {
        return max(triangleCreator(red,blue,true),triangleCreator(red,blue,false));
        
    }
};