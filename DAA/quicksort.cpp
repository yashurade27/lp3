#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;

// Deterministic Partition
int partitionDet(vector<int>& a, int low, int high, int& comp) {
    int pivot = a[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        comp++;
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[low], a[i]);
    return i;
}

// Deterministic Quick Sort
void quickSortDet(vector<int>& a, int low, int high, int& comp) {
    if (low < high) {
        int p = partitionDet(a, low, high, comp);

        quickSortDet(a, low, p - 1, comp);
        quickSortDet(a, p + 1, high, comp);
    }
}

// Randomized Partition
int partitionRand(vector<int>& a, int low, int high, int& comp) {
    int r = low + rand() % (high - low + 1);
    swap(a[low], a[r]);

    return partitionDet(a, low, high, comp);
}

// Randomized Quick Sort
void quickSortRand(vector<int>& a, int low, int high, int& comp) {
    if (low < high) {
        int p = partitionRand(a, low, high, comp);

        quickSortRand(a, low, p - 1, comp);
        quickSortRand(a, p + 1, high, comp);
    }
}

// Display Array
void display(vector<int>& a) {
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n), b(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    int compDet = 0, compRand = 0;

    // Deterministic Quick Sort
    auto start1 = high_resolution_clock::now();

    quickSortDet(a, 0, n - 1, compDet);

    auto end1 = high_resolution_clock::now();

    // Randomized Quick Sort
    auto start2 = high_resolution_clock::now();

    quickSortRand(b, 0, n - 1, compRand);

    auto end2 = high_resolution_clock::now();

    auto timeDet = duration_cast<microseconds>(end1 - start1).count();
    auto timeRand = duration_cast<microseconds>(end2 - start2).count();

    cout << "\nDeterministic Quick Sort:\n";
    display(a);
    cout << "Comparisons: " << compDet << endl;
    cout << "Time: " << timeDet << " microseconds\n";

    cout << "\nRandomized Quick Sort:\n";
    display(b);
    cout << "Comparisons: " << compRand << endl;
    cout << "Time: " << timeRand << " microseconds\n";

    return 0;
}