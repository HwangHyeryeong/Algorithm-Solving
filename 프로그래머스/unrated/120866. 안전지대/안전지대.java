class Solution {
    public int solution(int[][] board) {
        int[] dx = {-1, 0, 1, -1, 1, -1, 0, 1};
        int[] dy = {-1, -1, -1, 0, 0, 1, 1, 1};
        int n = board[0].length;
        
        if(n == 1){
            return (board[0][0] == 1)? 0 : 1;
        }
        
        int answer = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 1){
                    answer++;
                    for(int k = 0; k < 8; k++){
                        if(i+dy[k] >= 0 && i+dy[k] < n && j+dx[k] >= 0 && j+dx[k] < n){
                            if(board[i+dy[k]][j+dx[k]] == 0){
                                board[i+dy[k]][j+dx[k]] = 2;
                                answer++;
                            } 
                        }
                    }
                }
            }
        }
         
        return (n * n - answer);
    }
}