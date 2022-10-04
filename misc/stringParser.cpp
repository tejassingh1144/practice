#include <bits/stdc++.h>
using namespace std;

map<string,string> map2;
map<string,string> map1;

bool evaluateRelation(string str1, string str2){
    if(map1.find(str1) != map1.end()){
        if(map1.at(str1).compare(str2) == 0)
            return true;
        return false;
    }
    if(map2.find(str1) != map2.end()){
        if(map2.at(str1).compare(str2) == 0)
            return true;
        return false;
    }
    return false;
}

vector<string> stringParser(vector<string> strArr,int it){
    vector<string> tempV;
    while(true){
        if(strArr[it].compare(")") == 0 || it==strArr.size()-1){
            tempV.push_back(")");
            return tempV;
        }
        if(strArr[it].compare("(") == 0){
            vector<string> sub = stringParser(strArr,it+1);
            tempV.push_back("(");
            tempV.insert(tempV.end(),sub.begin(),sub.end());        
            stack<char> stack;
            stack.push('(');
            it++;
            while(!stack.empty()){
                if(strArr[it][0] == ')')
                    stack.pop();
                else if(strArr[it][0] == '(')
                    stack.push('(');
                it++;
            }
        }
        else if(strArr[it].compare("AND") != 0 && strArr[it].compare("OR") != 0){
            bool var = evaluateRelation(strArr[it],strArr[it+2]);
            if(var==true)
                tempV.push_back("true");
            else
                tempV.push_back("false");
            it+=3;
        }
        else{
            tempV.push_back(strArr[it]);
            it++;
        }    
    }

}



int main(){
    string ranString;
    vector<string> strArr;

    cout << "The string to be evaluated: ";
    getline(cin,ranString);
    stringstream ss(ranString);

    string word;
    while(ss >> word){
        strArr.push_back(word);
    }         
    while(true){
        string key,value;
        cout << "Enter key: " ;
        getline(cin,key);
        if(key.compare("")==0)
            break;
        cout << "Enter value: ";
        getline(cin,value);
        map1.insert({key,value});
        map2.insert({value,key});
    }
    strArr.push_back(" ");
    vector<string> result = stringParser(strArr,0);
    for(int i=0; i< result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}