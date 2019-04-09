vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string>str_codes{""}, str_codes_aux;
    for(int i=0;i<A;i++){
        str_codes_aux=vector<string>();
        for(int i=0;i<(int)str_codes.size();i++)
            str_codes_aux.push_back("0"+str_codes[i]);
        for(int i=(int)str_codes.size()-1;i>=0;i--)
            str_codes_aux.push_back("1"+str_codes[i]);
        str_codes=str_codes_aux;
    }

    vector<int>response;
    int expo2,num;
    for(string gray_code:str_codes){
        expo2=1;
        num=0;
        for(int i=(int)gray_code.size()-1;i>=0;i--, expo2*=2)
            num += expo2*(gray_code[i]-'0');
        response.push_back(num);
    }
    return response;
}
