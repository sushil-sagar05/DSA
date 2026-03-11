class Solution {
public:
    int bitwiseComplement(int n) {
        int result=0,counter=0;
        if(n==0) return 1;
        while(n){
            int r=n%2;
            result+=pow(2,counter)*!r;
            n=n/2;
            counter++;
        }
        return result;
    }
};