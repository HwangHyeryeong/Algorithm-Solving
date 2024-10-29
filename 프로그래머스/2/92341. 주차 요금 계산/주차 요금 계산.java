import java.util.*;

class Solution {
    int basicTime, basicFare, unitTime, unitFare;
    
    public List<Integer> solution(int[] fees, String[] records) {
        basicTime = fees[0]; basicFare = fees[1]; unitTime = fees[2]; unitFare = fees[3];
        
        Map<String, Integer> history = new TreeMap<>();
        Map<String, Integer> parkingTimes = new TreeMap<>();
        List<Integer> answer = new ArrayList<>();
        
        //주차 기록 처리
        for(String record : records){
            String[] parts = record.split(" ");
            int time = timeToMin(parts[0]);
            String carNum = parts[1];
            String type = parts[2];
            
            if(type.equals("IN")){
                history.put(carNum, time);
            }
            else{ // "OUT"
                int inTime = history.get(carNum);
                int parkingTime = time - inTime;
                
                //이전에 주차한 적 있는 차량인 경우 
                if(parkingTimes.containsKey(carNum)){
                    parkingTime += parkingTimes.get(carNum);
                }
                parkingTimes.put(carNum, parkingTime);
                history.remove(carNum); //출차 시 입차 기록 삭제
            }
        }
            
        //주차장에서 나가지 않는 차량 주차시간 계산
        int outTime = timeToMin("23:59");
        for(String key : history.keySet()){
            int inTime = history.get(key);
            int parkingTime = outTime - inTime;
                
            //이전에 주차한 적 있는 차량인 경우 
            if(parkingTimes.containsKey(key)){
                parkingTime += parkingTimes.get(key);
            }
            parkingTimes.put(key, parkingTime);
            
        }
            
        // 결과를 List에 추가
        for (String key : parkingTimes.keySet()) {
            answer.add(calcFare(parkingTimes.get(key)));
        }
        
        return answer;
    }
    
    public int timeToMin(String time){
        String[] parts = time.split(":");
        int hours = Integer.parseInt(parts[0]);
        int mins = Integer.parseInt(parts[1]);
        
        return (hours * 60 + mins);
    }
    
    public int calcFare(int time){
        int fare = basicFare;
        
        if(time > basicTime){
            time -= basicTime;
            if(time % unitTime == 0) {
                fare += (time / unitTime) * unitFare;
            }
            else{
                fare += (time / unitTime + 1) * unitFare;
            }        
        }
        
        return fare;
    }
}