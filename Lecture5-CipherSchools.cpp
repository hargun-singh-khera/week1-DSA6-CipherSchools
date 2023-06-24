#include<bits/stdc++.h>
using namespace std;

int rainWater(vector<int>& heights) {
    int n = heights.size();

    vector<int>lmax(n),rmax(n);
    lmax[0]= heights[0];
    rmax[n-1]=heights[n-1];

    for(int i = 1;i<n;i++){
        lmax[i] = max(heights[i], lmax[i-1]);
        rmax[n-i-1] = max(heights[n-i-1], rmax[n-i]);
    }
    int water = 0;
    for(int i = 1;i<n;i++){
        water += min(lmax[i], rmax[i]) - heights[i];
    }
    return water;
}

int main() {
    vector<int> heights = {2,3,5,1,2,8,1,2};

    int trappedWater = rainWater(heights);

    cout << "Trapped Water: " << trappedWater << endl;
}