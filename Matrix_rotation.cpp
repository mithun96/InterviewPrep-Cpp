class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int N = matrix.size();
        // Consider all squares one by one
        for (int x = 0; x < N / 2; x++)
        {
            // Consider elements in group of 4 in 
            // current square
            for (int y = x; y < N-x-1; y++)
            {
                // store current cell in temp variable
                int temp = mat[x][y];
     
                // move values from right to top
                mat[x][y] = mat[y][N-1-x];
     
                // move values from bottom to right
                mat[y][N-1-x] = mat[N-1-x][N-1-y];
     
                // move values from left to bottom
                mat[N-1-x][N-1-y] = mat[N-1-y][x];
     
                // assign temp to left
                mat[N-1-y][x] = temp;
            }
        }
    }
};



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < n - i - 1; j++){
                swap(matrix[i][j],matrix[j][n-1-i]);
                swap(matrix[n-1-j][i],matrix[i][j]);
                swap(matrix[n-1-i][n-1-j],matrix[n-1-j][i]);
            } 
        }
    }
};