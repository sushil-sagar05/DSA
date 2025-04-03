/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num){};
 */

class Solution {
public:
    int guessNumber(int n) {
       int low=1;
       int high=n;
       while(low<=high){
        // int guessnumber=floor((low+high)/2);
        int guessnumber=low+(high-low)/2;
        int value =guess(guessnumber);
        if(value==0){
            return guessnumber;
        }else if(value==-1){
            high=guessnumber-1;
        }else{
            low=guessnumber+1;
        }
       }
       return -1;
    }
};