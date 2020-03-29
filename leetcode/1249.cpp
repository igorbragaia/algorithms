class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<bool> valid(s.size(), true);
        stack<int>st;
        for(unsigned int i=0;i<s.size();i++)
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                if(st.empty())
                    valid[i] = false;
                else st.pop();  
            } 
        while(!st.empty()){
            valid[st.top()] = false;
            st.pop();
        }
        string response = "";
        for(unsigned int i=0;i<s.size();i++)
            if(valid[i])
                response += s[i];
        return response;
    }
};