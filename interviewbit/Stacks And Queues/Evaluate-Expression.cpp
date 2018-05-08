int Solution::evalRPN(vector<string> &A) {
    stack<int>stack;
    for(string el:A){
        if(el == "+"){
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a+b);
        } else if(el == "*"){
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(a*b);
        } else if(el == "/"){
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b/a);
        } else if(el == "-"){
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            stack.push(b-a);
        } else {
            stack.push(stoi(el));
        }
    }
    return stack.top();
}
