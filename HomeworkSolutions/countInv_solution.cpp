// Count inversions - homework
// Based off of mergesort
#include <vector>
#include <algorithm> // For copy

using namespace std;


int mergeInv(vector<int>& nums, vector<int>& left, vector<int>& right) {
	int i = 0, j = 0, k = 0;
	int numInv = 0;
	while ((j < left.size()) && (k < right.size())) {
		if (left[j] <= right[k]) {
			nums[i] = left[j];
			i++;
			j++;
		} else {
			nums[i] = right[k]; // Inversion
			i++;
			k++;
			numInv += left.size() - j; // Inverted by remaining elements in left
		}
	}
	while(j < left.size())  { // Remaining elements of left
		nums[i] = left[j];
		i++;
		j++;
	}
	while(k < right.size()) { // Inversion
		nums[i] = right[k];
		i++;
		k++;
	}
	return numInv;
}

int countInv(vector<int>&nums) {
	// Base case - one element, nothing to sort

	if (nums.size() > 1) {
		int mid = nums.size()/2;
		vector<int> left(mid);
		vector<int> right(nums.size()-mid);
		copy(nums.begin(), nums.begin() + mid, left.begin());
		copy(nums.begin() + mid, nums.end(), right.begin());
		int numInvLeft = countInv(left);
		int numInvRight = countInv(right);
		int numInvMerge = mergeInv(nums, left, right);
		return numInvLeft + numInvRight + numInvMerge;
		
	}
}



