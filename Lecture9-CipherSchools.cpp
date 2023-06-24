#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    vector<int>::iterator k;
    k= find(nums.begin(),nums.end(),target);
    if(k!=nums.end()){
        return k- nums.begin();
    }else{
        return -1;
    }
}
int main(){
    return 0;
}