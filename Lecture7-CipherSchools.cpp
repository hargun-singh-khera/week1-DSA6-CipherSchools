#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &nums){
    int p0 = 0;
    int p1 = 0;
    int p2 = nums.size() - 1;

    while(p1 <= p2){
        switch(nums[p1]){
            case 0:
                swap(nums[p0] , nums[p1]);
                p0++;
                p1++;
                break;
            case 1:
                p1++;
                break;
            case 2:
                swap(nums[p1], nums[p2]);
                p2--;
                break;
        }
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        if(row < 0){
            return false;
        }
        int r = 0;
        int c = matrix[0].size() - 1;

        while(c >= 0 && r <= row){
            if(target==matrix[r][c]){
                return true;
            }
            else if (target < matrix[r][c]){
                c--;
            }
            else if(target > matrix[r][c]){
                r++;
            }
        }
        return false;
    }

//Set Matrix zeros if matrix contains all positive numbers -Brute Force
void markRow(int i ,vector<vector<int>>& matrix){
    int m = matrix[0].size();
    for(int j =0;j<m;j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
void markCol(int j ,vector<vector<int>>& matrix){
    int n = matrix.size();
    for(int i = 0;i<n;i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
// void setZeroes(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     for(int i = 0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(matrix[i][j] == 0 ){
//                 markRow(i, matrix);
//                 markCol(j, matrix);
//             }
//         }
//     }
//     for(int i = 0;i<n;i++){
//         for(int j = 0;j<m;j++){
//             if(matrix[i][j] == -1){
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }
//! Set matrix zeros better approach
//  void setZeroes(vector<vector<int>>& matrix) {
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<int>rows(n, -1);
//     vector<int>cols(m, -1);
//     for(int i =0;i<n;i++){
//         for(int j = 0;j<m;j++){
//             if(matrix[i][j] == 0){
//                 rows[i]=1;
//                 cols[j]=1;
//             }
//         }
//     }
//     for(int i =0;i<n;i++){
//         for(int j = 0;j<m;j++){
//             if(rows[i] == 1 || cols[j] == 1){
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }
//! Set Matrix Zeros Best Approach 
 void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;
    for(int i =0 ;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
            
            if(j != 0){
                matrix[0][j] = 0;
            }
            else{
            col0 = 0;
            }
        }
    }
    }
    for(int i =1;i<n;i++){
        for(int j =1;j<m;j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j = 0;j<m;j++){
            matrix[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
}