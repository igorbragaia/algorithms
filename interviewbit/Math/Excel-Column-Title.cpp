string Solution::convertToTitle(int A) {
    string response="";
    while(A){
        if(A%26 == 0)
            response += 'Z';
        else
            response += ((A%26) - 1 + 'A');
        A /= 26;
    }
    for(int i=0;i<(int)response.size()/2;i++){
        char tmp=response[i];
        response[i]=response[(int)response.size()-1-i];
        response[(int)response.size()-1-i]=tmp;
    }
    return response;
}
