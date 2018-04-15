// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long int i = 1, f = (long long int) n, m, currentGuess;
        while(i <= f){
            m = (i + f) / 2;
            currentGuess = guess(m);
            if(currentGuess == 0) 
                return (int) m;
            if(currentGuess == -1) 
                f = m - 1;
            if(currentGuess == 1) 
                i = m + 1;
        }
    }
};