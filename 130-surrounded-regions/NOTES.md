// starting from boundary elements which are marked as 'O' , do a DFS, mark it is '#'
// those 'O's connected with boundary 'O's cannot be conquered. so marked them as '#'
​
// rest 'O's which are not marked, will be conquered
​
​
// CAREFUL writing this base condition-      <    board[i][j] != 'O'    >