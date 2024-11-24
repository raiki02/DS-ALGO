#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*
二分查找:
	1. 二分查找的前提是数组有序
	2. 二分查找的时间复杂度是O(logn)
	3. 二分查找的空间复杂度是O(1)
	4. 二分查找的缺点是数组必须是有序的
	5. 二分查找的优点是效率高
*/
#if 0
int binarySearch(vector<int>& nums, int target) {
	int left = 0;
	int right = nums.size() - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target) {
			return mid;
		}
		else if (nums[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

int main() {
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int target = 5;
	int res = binarySearch(nums, target);
	cout << res << endl;
	return 0;
}
#endif


/*
快速排序:
	1. 快速排序的时间复杂度是O(nlogn)
	2. 快速排序的空间复杂度是O(logn)
	3. 快速排序是不稳定的排序
	4. 快速排序的优点是效率高
	5. 快速排序的缺点是需要递归
*/

#if 0
void quickSort(vector<int>& nums, int left, int right) {
	if (left >= right) {
		return;
	}  
	int i = left;
	int j = right;
	int key = nums[left];
	while (i < j) {
		while (i < j && nums[j] >= key) {
			j--;
		}
		nums[i] = nums[j];
		while (i < j && nums[i] <= key) {
			i++;
		}
		nums[j] = nums[i];
	}
	nums[i] = key;
	quickSort(nums, left, i - 1);
	quickSort(nums, i + 1, right);
}

int main() {
	vector<int> nums = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	quickSort(nums, 0, nums.size() - 1);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}
     
#endif

/*
求大数的top K 问题:  	
	1.根堆	优先级队列
	2.快排划分
*/

//根堆

//快排划分
