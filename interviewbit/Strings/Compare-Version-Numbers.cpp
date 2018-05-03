vector<string> getArray(string&A){
	vector<string>nums;
	string tmp = "";
	for(char c:A){
		if(c != '.' and (tmp.size() > 0 or (tmp.size() == 0 and c != '0')))
			tmp += c;
		else if(tmp.size()>0){
            nums.push_back(tmp);
            tmp = "";   
		}
	}
	nums.push_back(tmp);
	return nums;
}

int Solution::compareVersion(string A, string B) {
	vector<string>nums1=getArray(A), nums2=getArray(B);
	for(int i = 0; i < max((int)nums1.size(),(int)nums2.size()); i++){
		string num1 = i < (int)nums1.size()?nums1[i]:"";
		string num2 = i < (int)nums2.size()?nums2[i]:"";

		if(num1.size() == num2.size()){
			if(num1 < num2)
				return -1;
			else if(num1 > num2)
				return 1;
		} else {
			if(num1.size() < num2.size())
				return -1;
			else if(num1.size() > num2.size())
				return 1;
		}
	}
	return 0;
}
