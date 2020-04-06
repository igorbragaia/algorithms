class Solution {
public:
    bool isHappy(int n) {
        set<int> ns;
        int m;
        while(n != 1){
            m = checkHappy(n);
            if(ns.find(m) == ns.end()){
                ns.insert(m);
                n = m;                
            }
            else
                return false;
        }
        return true;
    }
private:
    int checkHappy(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
};