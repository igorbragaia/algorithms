typedef long long int lli;

string solve(lli a, lli b, set<pair<lli,lli>>&hashset, string response){
    if(hashset.find(make_pair(a,b)) != hashset.end()){
        return "(" + response + ")";
    }
        
    if(a == 0)
        return response;
    
    hashset.insert(make_pair(a,b));

    bool gogo = false;
    while(a<b){
        a*=10;
        if(gogo)
            response += "0";
        gogo=true;
    }

    response += to_string(a/b);
    
    return solve(a%b, b, hashset, response);
}

string Solution::fractionToDecimal(int A, int B) {
    lli a =  (lli) A, b = (lli) B;
    string sign = ((a>0 and b<0) or (a<0 and b>0))?"-":"";
    a = abs(a), b = abs(b);
    
    set<pair<lli,lli>>hashset;

    if(a%b == 0)
        return sign+to_string(a/b);
    else {
        return sign+to_string(a/b) + "." + solve(a%b,b, hashset, "");
    }
}
