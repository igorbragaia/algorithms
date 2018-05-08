vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int>answer;
    stack<int>stack;
    for(int i = 0; i < (int)A.size(); i++){
        while(!stack.empty() and stack.top() >= A[i])
            stack.pop();
        if(stack.empty())
            answer.push_back(-1);
        else 
            answer.push_back(stack.top());
        stack.push(A[i]);

    }
    return answer;
}
