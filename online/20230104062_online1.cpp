#include <bits/stdc++.h>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void merges(vector<int> &b, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        int s1 = digitSum(b[left]);
        int s2 = digitSum(b[right]);
        if (s1 < s2)
            temp.push_back(b[left++]);
        else
            temp.push_back(b[right++]);
    }

    while (left <= mid) {
        temp.push_back(b[left++]);
    }
    while (right <= high) {
        temp.push_back(b[right++]);
    }
    for (int i = low; i <= high; i++) {
        b[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &a, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merges(a, low, mid, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << "   ";
    cout << endl;
    return 0;
}
