#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}
int quickSelect(vector<int> &a, int low, int high, int k) {
    if (low <= high) {
        int pi = partition(a, low, high);

        if (pi == k) return a[pi];
        else if (pi > k) return quickSelect(a, low, pi - 1, k);
        else return quickSelect(a, pi + 1, high, k);
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int kthSmallest = quickSelect(a, 0, n - 1, k - 1);
    cout << kthSmallest << endl;

    return 0;
}
