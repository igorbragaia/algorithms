stack<int>mainstack;
stack<int>minstack;

MinStack::MinStack() {
    mainstack=stack<int>();
    minstack=stack<int>();
}

void MinStack::push(int x) {
    mainstack.push(x);
    if(minstack.empty() || x<=minstack.top())
        minstack.push(x);
}

void MinStack::pop() {
    if(!mainstack.empty()){
        if(mainstack.top() == minstack.top())
            minstack.pop();
        mainstack.pop();
    }
}

int MinStack::top() {
    if(!mainstack.empty())
        return mainstack.top();
    else
        return -1;
}

int MinStack::getMin() {
    if(!minstack.empty())
        return minstack.top();
    else
        return -1;
}
