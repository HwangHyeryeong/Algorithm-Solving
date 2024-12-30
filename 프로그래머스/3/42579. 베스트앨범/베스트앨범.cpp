#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    //장르, 총재생횟수
    map<string, int> genrePlayCnt;
    //장르 -> {{재생횟수, 곡1}, {재생횟수, 곡2}, ...}
    map<string, vector<pair<int, int>>> genreMusicList;
    
    //데이터 저장
    for(int i = 0; i < genres.size(); i++){
        string genre = genres[i];
        genrePlayCnt[genre] += plays[i];
        genreMusicList[genre].push_back({-plays[i], i});
    }
    
    //장르별 총 재생횟수 다시 저장 -> 수록 순서 정하기 쉽게
    map<int, string> sortedTotalPlay;
    for(auto m : genrePlayCnt){
        sortedTotalPlay[-m.second] = m.first;
    }
    
    //장르 내 재생 횟수 정렬
    for(auto& music : genreMusicList){
        sort(music.second.begin(), music.second.end());
    }
    
    // 속한 노래가 많이 재생된 장르를 먼저 수록
    for(auto p : sortedTotalPlay){    
        string genre = p.second;
        vector<pair<int, int>> list = genreMusicList[genre];
        
        // 장르 내에서 많이 재생된 노래를 먼저 수록, 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록
        for(int i = 0; i < min((int)list.size(), 2); i++){
            answer.push_back(list[i].second);
        }
    }
    
    return answer;
}