class Solution {
public:
    vector<string> fizzBuzz(int n) {
  		vector<string>response;
  		for(int i = 1; i <= n; i++){
  			if(i%15 == 0){
  				response.push_back("FizzBuzz");
  			} else if(i%5 == 0){
  				response.push_back("Buzz");
  			} else if(i%3 == 0){
  				response.push_back("Fizz");
  			} else {
  				response.push_back(to_string(i));
  			}
  		}      
  		return response;
    }
};