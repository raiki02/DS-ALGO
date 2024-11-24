#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*
���ֲ���:
	1. ���ֲ��ҵ�ǰ������������
	2. ���ֲ��ҵ�ʱ�临�Ӷ���O(logn)
	3. ���ֲ��ҵĿռ临�Ӷ���O(1)
	4. ���ֲ��ҵ�ȱ������������������
	5. ���ֲ��ҵ��ŵ���Ч�ʸ�
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
��������:
	1. ���������ʱ�临�Ӷ���O(nlogn)
	2. ��������Ŀռ临�Ӷ���O(logn)
	3. ���������ǲ��ȶ�������
	4. ����������ŵ���Ч�ʸ�
	5. ���������ȱ������Ҫ�ݹ�
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
�������top K ����:  	
	1.����	���ȼ�����
	2.���Ż���
*/

//����

//���Ż���
