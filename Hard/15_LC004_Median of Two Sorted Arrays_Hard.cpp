
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> arr(nums1.size() + nums2.size());

        // Copy nums1
        for (int i = 0; i < nums1.size(); i++) {
            arr[i] = nums1[i];
        }

        // Copy nums2
        for (int j = 0; j < nums2.size(); j++) {
            arr[nums1.size() + j] = nums2[j];
        }

        // Sort combined array
        sort(arr.begin(), arr.end());

        int n = arr.size();

        // Odd number of elements
        if (n % 2 != 0) {
            return arr[n / 2];
        }
        // Even number of elements
        else {
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};
