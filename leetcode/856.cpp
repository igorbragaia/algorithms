class Solution {
public:
    int scoreOfParentheses(string S) {
    	stack<int>stack;
    	for(char c:S){
    		if(c == '('){
				stack.push(0);
    		}
    		else {
    			if(stack.top() == 0){
    				stack.pop();
    				
                    if(!stack.empty() and stack.top() > 0){
                        int top = stack.top();
                        stack.pop();
                        stack.push(top + 1);
                    }
                    else
                        stack.push(1);
                    
    			} else {
    				int top = 2*stack.top();
    				stack.pop();
    				stack.pop();
                    
                    
                    if(!stack.empty() and stack.top() > 0){
                        top += stack.top();
                        stack.pop();
                    }
                    stack.push(top);
    			}
    		}
    	}
    	return stack.top();   
    }
};
