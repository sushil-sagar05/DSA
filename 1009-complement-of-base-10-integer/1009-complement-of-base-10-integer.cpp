class Solution {
public:
    int bitwiseComplement(int n) {
        // Approach 1 T.C-> log(n)
        // int result=0,counter=0;
        // if(num==0) return 1;
        // while(num){
        //     int r=num%2;
        //     result+=pow(2,counter)*!r;
        //     num=num/2;
        //     counter++;
        // }
        // return result;

        // Approach 2 T.C-> O(1)
        int result=0,counter=0;
        if(n==0) return 1;
        int bits=floor(log2(n))+1;
        int mask=pow(2,bits)-1;
        return n^mask;
    }
};