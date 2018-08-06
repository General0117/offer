#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if(sequence.empty())
			return false;
		vector<int> len_left;
		vector<int> len_right;

		int i = 0;
		for(;i < sequence.size() - 1;++i) {
			if(sequence[i] < sequence[sequence.size() - 1])
				len_left.push_back(sequence[i]);
			else
				break;
		}

		for(;i < sequence.size() - 1; ++i) {
			if(sequence[i] > sequence[sequence.size() - 1])
				len_right.push_back(sequence[i]);
			else
				return false;
		}

		bool left = true,right = true;
		if(!len_left.empty()) {
			left = VerifySquenceOfBST(len_left);
		}
		if(!len_right.empty()) {
			right = VerifySquenceOfBST(len_right);
		}
		return left && right;
	}
};