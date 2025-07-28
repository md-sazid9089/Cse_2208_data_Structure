#include <bits/stdc++.h>
using namespace std;

// Standard partition function for QuickSort
int partition(vector<int>& a, int st, int ed) {
    int pivot = a[ed];
    int idx = st - 1;
    for (int j = st; j < ed; j++) {
        if (a[j] <= pivot) {
            idx++;
            swap(a[j], a[idx]);
        }
    }
    swap(a[idx + 1], a[ed]);
    return idx + 1;
}

// QuickSort function
void quickSort(vector<int>& a, int st, int ed) {
    if (st < ed) {
        int pivotIdx = partition(a, st, ed);
        quickSort(a, st, pivotIdx - 1);
        quickSort(a, pivotIdx + 1, ed);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> posValues;
    vector<int> posIndices;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 0) {
            posValues.push_back(arr[i]);
            posIndices.push_back(i);
        }
    }
    quickSort(posValues, 0, posValues.size() - 1);
    for (int i = 0; i < posIndices.size(); i++) {
        arr[posIndices[i]] = posValues[i];
    }
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

