import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int h = triangle.length;
        
        for(int i = 1; i < h; i++){
            for(int j = 0; j < triangle[i].length; j++){
                if(j > 0 && j < triangle[i].length - 1)
                    triangle[i][j] = Math.max(triangle[i - 1][j - 1] + triangle[i][j], triangle[i - 1][j] + triangle[i][j]);
                else if(j == 0)
                    triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
                else if(j == triangle[i].length - 1)
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
            }
        }                
        
        for(int i = 0; i < triangle[h-1].length; i++)
            answer = Math.max(answer, triangle[h-1][i]);
        
        return answer;
    }
}