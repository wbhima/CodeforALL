class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> temp = matrix;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) {
                if(matrix[i][j] == 0) setZero(temp,i,j);
            }
        }
        matrix = temp;
    }
    
    void setZero(vector<vector<int>>& temp,int i, int j) {
        for(int row = 0; row < temp[i].size();row++) {
            temp[i][row] = 0;
        }
        for(int col = 0; col < temp.size();col++) {
            temp[col][j] = 0;
        }
    }
};