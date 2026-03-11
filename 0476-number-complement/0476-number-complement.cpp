class Solution {
public:
    int findComplement(int num) {
        int result=0,counter=0;
        if(num==0) return 1;
        while(num){
            int r=num%2;
            result+=pow(2,counter)*!r;
            num=num/2;
            counter++;
        }
        return result;
    }
};