#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeCount(vector<pair<int,int>>& arr, int low, int mid, int high, vector<int>& result) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<pair<int,int>> left(n1), right(n2);
        for (int i = 0; i < n1; i++) left[i] = arr[low + i];
        for (int j = 0; j < n2; j++) right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = low;
        int countRightSmaller = 0;

        while (i < n1 && j < n2) {
            if (left[i].first <= right[j].first) {
                // all counted smaller are for this element
                result[left[i].second] += countRightSmaller;
                arr[k++] = left[i++];
            } else {
                // right[j] is smaller
                countRightSmaller++;
                arr[k++] = right[j++];
            }
        }

        while (i < n1) {
            result[left[i].second] += countRightSmaller;
            arr[k++] = left[i++];
        }
        while (j < n2) {
            arr[k++] = right[j++];
        }
    }

    void mergeSort(vector<pair<int,int>>& arr, int low, int high, vector<int>& result) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, result);
        mergeSort(arr, mid + 1, high, result);
        mergeCount(arr, low, mid, high, result);
    }

    vector<int> constructLowerArray(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> arrWithIdx(n);
        for (int i = 0; i < n; i++) arrWithIdx[i] = {arr[i], i};

        vector<int> result(n, 0);
        mergeSort(arrWithIdx, 0, n - 1, result);
        return result;
    }
};
