#include<bits/stdc++.h>
using namespace std;

// pass by value/pass by reference
void mergeSortedArrays(vector<int> &a, int m , vector<int> &b, int n){
     int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (a[i] > b[j]) {
                a[k] = a[i];
                k--;
                i--;
            } else {
                a[k] = b[j];
                k--;
                j--;
            }
        }
        while (j >= 0) {
            a[k] = b[j];
            k--;
            j--;
        }
}
int main(){
    
    vector<int> a = {1, 2, 3, 4, 5, 6, 6};
    vector<int> b = {2, 5, 6, 8};
    int m = 3;
    int n = 3;
    
    mergeSortedArrays(a,m,b,n);
    
    cout << "After merging: ";
    for(int i=0;i<a.size();i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
