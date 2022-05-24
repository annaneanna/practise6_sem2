#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int arr_size = 5;
void find_terms(vector<int> arr, int k, vector<pair<int, int>>& res) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i; j < arr.size(); j++) {
			if (arr[i] + arr[j] == k) {
				pair<int, int> res_iter = make_pair(arr[i], arr[j]);
				res.push_back(res_iter);
			}
		}
	}
	return;
}
int binarysearch(vector<int>&mas, int l, int r, int digit) {
	if (r >= l) {
		int mid = l + ((r - l) / 2);
		if (mas[mid] == digit) {
			return mid;
		}

		if (digit < mas[mid]) {
			return binarysearch(mas, l, mid - 1, digit);
		}
		return binarysearch(mas, mid + 1, r, digit);
	}
	else {
		return -1;
	}

}



int main() {

	vector<int>arr = { 3,6,3,1,2,4,6,7,1 };
	vector<pair<int, int>>res;
	
	sort(arr.begin(), arr.end());
	cout << binarysearch(arr, 0, arr.size() - 1, 1)<<endl;

	int k = 5;

	find_terms(arr, k, res);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << ' ' << res[i].second << endl;
	}

	

	return 0;
}