#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int findkthLargest(vector<int>& nums, int k, int left, int right) {
		if (k == 1) {
			int max = nums[left];
			for (int i = left+1; i <= right; i++) {
				if (nums[i] > max) max = nums[i];
			}
			return max;
		}
		if (k == right-left+1) {
			int min = nums[left];
			for (int i = left+1; i <= right; i++) {
				if (nums[i] < min) min = nums[i];
			}
			return min;
		}
        int flag = rand()%(right-left);
        //cout << "flag: " << flag << endl;
        int keynum = flag+left;
        int key = nums[keynum];
        int low = left, high = right;
        swap(nums[keynum], nums[left]);
        while (low < high) {
            while (nums[high] >= key && low < high) {
                high--;
            }
            nums[low] = nums[high];
            while (nums[low] <= key && low < high) {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = key;
        if ((right-low) >= k) {
            return findkthLargest(nums, k, low+1, right);
        } else if (right-low+1 == k) {
            return key;
        } else {
            return findkthLargest(nums, k-right+low-1, left, low-1);
        }
    }
int findKthLargest(vector<int>& nums, int k) {
        return findkthLargest(nums, k, 0, nums.size()-1);
    }

    
int main() {
	vector<int> nums;
	int n, k;
	cin >> n >> k;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		nums.push_back(x);
	}
//	for (int i = 0; i < nums.size(); i++) {
//		cout << nums[i] << " ";
//	}
//	cout << endl; 
//	cout << nums.size() << endl;
	cout << findKthLargest(nums, k) << endl;
} 
