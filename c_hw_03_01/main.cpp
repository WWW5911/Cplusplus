#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string str_toupper(string str){
    string temp = "";
    for(int i = 0; i < str.length(); ++i)
        temp += toupper(str.at(i));
    return temp;
}

int main(){
    string orgin, comp;
    
    while(!cin.eof()){
        cin>>orgin>>comp;
        int l_orgin = orgin.length(), l_comp = comp.length(), count = 0;
        vector<int> ans;
        map<char, int> charMap;
        orgin = str_toupper(orgin);
        comp = str_toupper(comp);
        for(int i = 0; i+l_comp < l_orgin; ++i){
            int temp = orgin.find(comp, i);
            if(temp < l_orgin && temp >= 0){
                ans.push_back(temp);
                i = temp;
                ++count;
            }
        }
        for(int i = 0; i<l_orgin; ++i)
            if(charMap.find(orgin.at(i)) != charMap.end())
                ++charMap[orgin.at(i)];
            else charMap[orgin.at(i)] = 1;    
        cout<< charMap['A'] <<" "<< charMap['C'] <<" "<< charMap['G'] <<" "<< charMap['T'] <<endl;
        for(int i = 0; i<ans.size(); ++i)
            cout<< ans[i] << " ";
        cout<<count<<endl;
    }
    return 0;
}