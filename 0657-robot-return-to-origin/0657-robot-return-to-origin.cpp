class Solution {
public:
    bool judgeCircle(string moves) {
        int cnt_U=0,cnt_D=0,cnt_R=0,cnt_L=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U'){
                cnt_U++;
            }else if(moves[i]=='D'){
                cnt_D++;
            }else if(moves[i]=='R'){
                cnt_R++;
            }else{
                cnt_L++;
            }
        }
        if(cnt_U==cnt_D&&cnt_L==cnt_R) return true;
        return false;
    }
};