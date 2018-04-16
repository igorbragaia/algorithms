typedef pair<int,int> pp;
typedef pair<pp, pp> ppp;

class Solution {
public:
    int nextGreaterElement(int n) {
  		int nCeil = ceil(log2(n)), nFloor = floor(log2(n));
  		int desiredBits = countBits(n);
  		stack<ppp> stack;
		stack.push(make_pair(make_pair(1, nCeil), make_pair(pow(2,nFloor), pow(2, nCeil) - 1)));
  		while(stack.top().first.first != stack.top().first.second){
  			ppp top = stack.top();
  			if(n > (3 / 2) * top.second.first){
  				top.first.first++;
  				top.second.first = (3 / 2) * top.second.first;
  			} else {
  				top.first.second--;
  				top.second.second = (3 / 2) * top.second.first - 1;
  			}
  			stack.push(top);
  		}
  		while(stack.top().first.first == desiredBits or stack.top().first.second == desiredBits)
  			stack.pop();
  		ppp answer = stack.top();
  		while(answer.first.second != desiredBits){
			answer.first.second--;
			answer.second.second = (3 / 2) * answer.second.first - 1;
  		}
  		while(answer.first.first != desiredBits){
			answer.first.first++;
			answer.second.first = (3 / 2) * answer.second.first;
  		}
  		return answer.second.first;
    }
private:
	int countBits(int num){
		int answer = 0;
		while(num){
			answer += num%2;
			num >>= 1;
		}
		return answer;
	}
};