#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& h) {
    int totWater = 0;
    int left[h.size()];
    int right[h.size()];
    left[0] = h[0];
    for (int i = 1; i < h.size(); i++) {
        left[i] = max(left[i - 1], h[i]);
    }
    right[h.size() - 1] = h[h.size() - 1];
    for (int i = h.size() - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], h[i]);
    }
    for (int i = 0; i < h.size(); i++) {
        int currWater = 0;
        currWater = min(left[i], right[i]) - h[i];
        totWater += currWater;
    }
    return totWater;
}

int main() {
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};  

    int trappedWater = trap(heights);

    cout << trappedWater << endl;

    return 0;
}