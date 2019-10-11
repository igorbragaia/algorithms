class Solution {
public:
    string addBinary(string a, string b) {
        string sum="";

        int i=(int)a.size()-1, j=(int)b.size()-1, value, carry=0;
        while(i >= 0 || j >= 0){
            value=carry;
            carry=0;
            if(i>=0)
                value += a[i--]=='1';
            if(j>=0)
                value += b[j--]=='1';
            if(value>=2){
                value %= 2;
                carry=1;
            }
            sum += value?"1":"0";
        }
        if(carry)
            sum += "1";

        for(int i=0;i<(int)sum.size()/2;i++)
            swap(sum[i], sum[(int)sum.size()-1-i]);
        return sum;
    }
};