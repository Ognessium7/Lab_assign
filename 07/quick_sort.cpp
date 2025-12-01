#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int pivotIndex = partition(arr, low, high);
    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
}

void print_vec(const vector<int>& arr) {
    cout << "{";
    for (int v : arr) cout << v << ", ";
    cout << "}" << endl;
}

int main() {
    vector<int> arr = {1,2,6,4,2,0,3,2,1,7,6,5};
    quickSort(arr, 0, arr.size() - 1);
    print_vec(arr);
    return 0;
}
