typedef long long int lli;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        lli i=1, j=n, k, res=0;
        while(i<=j and !res){
            k=(i+j)/2;
            if((k==1 and isBadVersion(k)) or (isBadVersion(k) and !isBadVersion(k-1)))
                res=k;
            if(isBadVersion(k))
                j=k-1;
            else
                i=k+1;
        }
        return (int)res;
    }
};

f t
i=1, j=2, m=1

