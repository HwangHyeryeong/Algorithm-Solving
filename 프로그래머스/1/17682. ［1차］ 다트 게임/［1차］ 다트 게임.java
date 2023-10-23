import java.util.*;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        
        int before = 0, now = 0;
        for(int i = 0; i < dartResult.length(); i++){
            char c = dartResult.charAt(i);
            
            if(c == 'S');
            else if(c == 'D') now *= now;
            else if(c =='T') now = (now * now * now);
            else if(c == '*') {
                before *= 2;
                now *= 2;
            }
            else if(c == '#'){
                now *= -1;
            }
            else{
                answer += before;
                before = now;
                now = Character.getNumericValue(c);
                if(now == 1 && dartResult.charAt(i + 1) == '0'){
                    now = 10;
                    i++;
                }   
            }
        }
        answer += (now + before);
        
        return answer;
    }
}