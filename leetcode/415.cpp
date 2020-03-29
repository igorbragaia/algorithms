class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int carry = 0, n;
        reverse(num1);
        reverse(num2);
        unsigned int maxLen = max(num1.size(), num2.size());
        for(unsigned int i=0;i<maxLen;i++){
            n = carry + (i<num1.size()?(num1[i]-'0'):0) + (i<num2.size()?(num2[i]-'0'):0);
            carry = n/10;
            n %= 10;
            res += '0' + n;
        }
        if(carry) res += "1";
        
        reverse(res);
        return res;
    }
private:
    void reverse(string&input){
        for(unsigned int i=0;i<input.size()/2;i++)
            swap(input[i], input[input.size()-1-i]);
    }
};