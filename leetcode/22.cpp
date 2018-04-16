typedef pair<int,int> pp;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>answer;
        queue<pair<string,pp>>queue;
        queue.push(make_pair("",make_pair(n,n)));
        while(!queue.empty()){
            pair<string,pp> front = queue.front();
            queue.pop();

            if(front.second.first == 0 and front.second.second == 0)
                answer.push_back(front.first);
            if(front.second.first > 0){
                string s = front.first;
                s += "(";
                queue.push(make_pair(s, make_pair(front.second.first - 1, front.second.second)));
            } 
            if(front.second.second > front.second.first){
                string s = front.first;
                s += ")";
                queue.push(make_pair(s, make_pair(front.second.first, front.second.second - 1)));			
            }
        }
        return answer;
    }
};