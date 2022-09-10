#include <bits/stdc++.h>
using namespace std;
// Recursive Solution
// The idea is to loop over the length of combination, rather than the candidate numbers, and generate all combinations for a given length with the help of backtracking technique.
// TC: O(N * 2^N)
// SC: O(N)
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> ans;
	backtrack(nums, 0, ans, res);
	return res;
}

void backtrack(vector<int> &nums, int index, vector<int> ans, vector<vector<int>> &res) {
	res.push_back(ans);

	for (int i = index; i < nums.size(); i++) {
		ans.push_back(nums[i]);
		backtrack(nums, i+1, ans, res);
		ans.pop_back();
	}
}

// Iterative Solution
// Let's start from empty subset in output list. At each step one takes new integer into consideration and generates new subsets from the existing ones.
// TC: O(N 2^N)
// SC: O(N 2^N)
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> output;
	output.push_back({});

	for (int i = 0; i < nums.size(); i++) {
		vector<vector<int>> newSubsets;
		for (vector<int> curr: output) {
			curr.push_back(nums[i]);
			newSubsets.push_back(curr);
		}

		for (vector<int> curr: newSubsets) {
		   output.push_back(curr);
		}
	}

	return output;
}

// Bit-Manipulation Solution
// The idea is that we map each subset to a bitmask of length n, where 1 on the ith position in bitmask means the presence of nums[i] in the subset, and 0 means its absence.
// TC: O(N 2^N)
// SC: O(N 2^N)
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> output;
	int n = pow(2, nums.size());

	for (int i = 0; i < n; i++) {
		vector<int> curr;
		for (int j = 0; j < nums.size(); j++) {
			if (i & 1 << j) {
				curr.push_back(nums[j]);
			}
		}
		output.push_back(curr);
	}

	return output;
}