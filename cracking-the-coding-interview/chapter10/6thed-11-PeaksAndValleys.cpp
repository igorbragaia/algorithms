#include<bits/stdc++.h>
using namespace std;

// codeforces 652B - z-sort

class Solution{
public:
	vector<int> waveSort(vector<int> array){
		if((int) array.size() < 2)
			return array;

		if(array[0] > array[1])
			swap(array[0], array[1]);
		int mightBeValley = false;
		for(int i = 1; i < (int) array.size() - 1; i++){
			if(mightBeValley){
				if(array[i] > array[i + 1])	
					swap(array[i], array[i + 1]);
				mightBeValley = false;	
			} else {
				if(array[i] < array[i + 1])
					swap(array[i], array[i + 1]);
				mightBeValley = true;
			}
		}
		return array;
	}
private:
	void swap(int&a,int&b){
		int tmp = a;
		a = b;
		b = tmp;	
	}
};

int main(){
	int n, x;
	vector<int> array;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		array.push_back(x);
	}
	array = Solution().waveSort(array);
	cout << array[0];
	for(int i = 1; i < array.size(); i++)
		cout << " " << array[i];
	cout << endl;	
	return 0;
}