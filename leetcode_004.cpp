#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int find_kth(vector<int>::const_iterator, int, vector<int>::const_iterator, int, int);
double findMedianSortedArrays(vector<int>&, vector<int>&);
double findMedianSortedArrays2(vector<int>&, vector<int>&);

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
	vector<int> num;
	num = nums1;
	num.insert(num.end(),
		make_move_iterator(nums2.begin()),
		make_move_iterator(nums2.end()));
	sort(num.begin(), num.end());
	for (auto it : num){
		cout << it << " ";
	}
	cout << endl;
	return (double)( num.size()%2 ? num[num.size()>>1] : ( num[(num.size()-1)>>1] + num[num.size() >> 1] )/2.0 ) ;
	
}

double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2){
	const int m = nums1.size();
	const int n = nums2.size();
	int total = m+n;
	if (total & 0x1) return find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
	else return (find_kth(nums1.begin(), m, nums2.begin(), n, total / 2) + find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
}

int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k){
	//m must be no more than n
	if (m > n) return find_kth(B, n, A, m, k);
	if (m == 0) return *(B + k - 1);
	if (k == 1) return min(*A, *B);

	int ia = min(k / 2, m), ib = k - ia;
	if (*(A + ia - 1) < *(B + ib - 1)) return find_kth(A + ia, m - ia, B, n, k - ia);
	else if (*(A + ia - 1) > *(B + ib - 1)) return find_kth(A, m, B + ib, n - ib, k - ib);
	else return A[ia - 1];
}

int main(){
	vector<int> nums1{};
	vector<int> nums2{2 ,3};
	
	cout << "method 1 : " << findMedianSortedArrays(nums1, nums2) << endl;
	cout << "method 2 : " << findMedianSortedArrays2(nums1, nums2) << endl;
}