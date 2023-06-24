#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> power(vector<int>& nums){
    vector<vector<int>> TotalSubsets;
    int n=nums.size();
    for(int num=0;num<=pow(2,n)-1;num++){
        vector<int> sub;
        for(int i=0;i<=n-1;i++){
            if(num&(1<<i)){
                sub.push_back(nums[i]);
            }
        }
        TotalSubsets.push_back(sub);
    }
    return TotalSubsets;
}