#include <bits/stdc++.h>
using namespace std;

// Partition function like QuickSort
int partition(vector<int>& a, int st, int ed) {
    int pivot = a[ed];
    int i = st - 1;
    for (int j = st; j < ed; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[ed]);
    return i + 1;
}

// QuickSelect: find kth smallest element
int quickSelect(vector<int>& a, int st, int ed, int k) {
    if (st == ed) return a[st];
    int pivotIdx = partition(a, st, ed);

    if (pivotIdx == k) return a[pivotIdx];
    else if (pivotIdx > k) return quickSelect(a, st, pivotIdx - 1, k);
    else return quickSelect(a, pivotIdx + 1, ed, k);
}

// Median function
double findMedian(vector<int>& a) {
    int n = a.size();
    if (n % 2 == 1) {
        return quickSelect(a, 0, n - 1, n / 2);
    } else {
        int m1 = quickSelect(a, 0, n - 1, n / 2);
        int m2 = quickSelect(a, 0, n - 1, n / 2 - 1);
        return (m1 + m2) / 2.0;
    }
}

int main() {
    vector<int> a = {12, 31, 35, 8, 32, 17};
    double median = findMedian(a);
    cout << "Median = " << median << endl;
    return 0;
}
