#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

template<typename T>
void print(T &node){
    cout<<node<<" ";
}
char turn_to_lower(char c){
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    else
        return c;
}
bool opR(int item){
    if(item % 3 == 0) return true;
    return false;
}

int main(){
    vector<char> tr_L, tr_L2;
    for(int i = 65; i < 75; ++i)
        tr_L.push_back(i);
    for_each(tr_L.begin(), tr_L.end(), print<char>);
    tr_L2.resize(tr_L.size());
    transform(tr_L.begin(), tr_L.end(), tr_L2.begin(), turn_to_lower);
    cout<<endl;
    for_each(tr_L2.begin(), tr_L2.end(), print<char>);
    cout<<endl;

    int arr[3] = {10, 20, 30};
    cout << accumulate(arr, arr+3, 0 )<<endl;
    cout << accumulate(arr, arr+3, 0, [](int a, int w) {if(w <= 10) return a; return a + w;} );
    cout<<endl;cout<<endl;

    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(8);
    vec.push_back(12);
    vec.push_back(22);
    vec.push_back(33);
    vec.erase(remove(vec.begin(), vec.end(), 3),  vec.end());

    for_each(vec.begin(), vec.end(), print<int>);
    cout<<endl;
    vec.erase(vec.begin(), vec.end());
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(12);
    vec.push_back(22);
    vec.push_back(33);
    remove_if(vec.begin(), vec.end(), opR);
    for_each(vec.begin(), vec.end(), print<int>);
    cout<<endl;

    vec.erase(vec.begin(), vec.end());
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(12);
    vec.push_back(22);
    vec.push_back(33);
    vec.erase(remove_if(vec.begin(), vec.end(), opR),  vec.end());
    for_each(vec.begin(), vec.end(), print<int>);
    cout<<endl;
}