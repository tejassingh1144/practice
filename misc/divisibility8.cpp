#include <bits/stdc++.h>
using namespace std;
bool exist(int n,int i){
    if(n/100 == i)
        return true;
    if((n%10) == i)
        return true;
    if(((n/10) % 10) == i)
        return true;
    return false;
}
int main(){
    int n,*arr;
    vector<int*> divisible;
    vector<int*> checkDiv;
    // cin >> n;
    // arr = new int[n];
    // for(int i=0;i<n;i++)
    //     cin >> arr[i];
    int count = 0; 
    for(int i=0;i<1000;i+=8){
        if(i%8 == 0){
            int* arr = new int[3];
            int* arr2 = new int[3];
            divisible.push_back(arr);
            checkDiv.push_back(arr2);
            int tempI = i;
            for(int j=2;j>=0;j--){
                checkDiv[count][j] = 0;
                divisible[count][j] = tempI%10;
                tempI/=10; 
            }
            count++;
        }
    }
    cout << endl;
        
}