class Solution {
public:
    int brokenCalc(int X, int Y) {
        int cnt=0;
        while(X!=Y){
            if(X>Y){
                cnt+=X-Y;
                break;
            }else if(Y%2==0){
                Y/=2;
                cnt++;
            }else{
                Y=(Y+1)/2;cnt+=2;
            }
        }
        return cnt;
    }
};
