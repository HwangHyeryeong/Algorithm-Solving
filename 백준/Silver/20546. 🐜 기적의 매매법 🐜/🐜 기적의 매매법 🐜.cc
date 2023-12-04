#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int cash; cin >> cash;
    vector<int> price(14, 0);
    
    int decline = 0, rise = 0;
    int smMoney = cash, smStock = 0, jhMoney = cash, jhStock = 0;
    for(int i = 0; i < 14; i++){
        cin >> price[i];
        
        if(i > 0){
            if(price[i] > price[i - 1]) {
                rise++; decline = 0;
            }
            else if(price[i] < price[i - 1]) {
                decline++; rise = 0;
            }
            else{
                decline = 0; rise = 0;
            }
        }
        
        if(jhMoney >= price[i]){
            int cnt = jhMoney / price[i];
            jhStock += cnt;
            jhMoney -= cnt * price[i];
        }
        
        if(decline == 3){
            int cnt = smMoney / price[i];
            smStock += cnt;
            smMoney -= cnt * price[i];
        }
        else if(rise == 3){
            smMoney += smStock * price[i];
            smStock = 0;
        }
    }
    
    smMoney += smStock * price[13];
    jhMoney += jhStock * price[13];
    
    if(smMoney > jhMoney) cout << "TIMING";
    else if(smMoney < jhMoney) cout << "BNP";
    else cout << "SAMESAME";
    
    return 0;
}