class Solution {
public:
    pair<int, int> findUnassignedCell(vector<vector<char>>board) {
   
    int i,j;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if(board[i][j] == '.'){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

bool isSafe(vector<vector<char>>board, int x, int y, int m) {
    
    int a = x/3;
    int b = y/3;
    
  char k= (char)m+'0';
   int i,j;
   // row
   i=x;
   for(j=0; j<9; j++) {
       if(board[i][j] == k){
           return false;
       }
   }
    
  //col
    j=y;
    for(i=0;i<9;i++){
        if(board[i][j] == k){
            return false;
        }
    }
    
    // block;
    for(i=a*3; i<a*3+3; i++){
        for(j=b*3; j<b*3+3 ; j++){
            if(board[i][j]== k){
                return false;
            }
        }
    }
    
    return true;
}
bool func(vector<vector<char>>& board) {
    
    pair<int, int> p = findUnassignedCell(board);
    
    if(p.first == -1 && p.second == -1){
        return true; // comp soduku
    }
    
    int i = p.first;
    int j = p.second;
    
    for(int k=1; k<=9; k++) {
        if(isSafe(board, i, j, k)) {
            board[i][j] = (char)k + '0';
            if(func(board)){
                return 1;
            }
            board[i][j]='.';
        }
    }
    
    return 0;
}
    void solveSudoku(vector<vector<char>>& board) {
        
        bool canBeSolvable = func(board);
        // canBeSolvable does not make any sense because there is always a solution, but this will works
        // in case when you want to return whether any solution is possible or not.
    }
};

