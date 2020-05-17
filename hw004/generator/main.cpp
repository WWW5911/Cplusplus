#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <vector>
#include <time.h>
#include "varible.h"

using namespace std;

ofstream outfile("out.txt");

template<typename T>
void write(T &node){
    outfile<<node<<" ";
}

int main(){

    srand( time(NULL) );
    map<string , int> used, isfull;
    vector<string> city_list;
    int arr[citys.size()] = {0};
    int N = rand() % (20 - 2 + 1) + 2;
    int K = rand() % ( (N*(N-1)/2 )- (N-1) + 1) + (N-1);
    outfile<<N<<" "<<K<<endl;
    for(int i = 0; i <N; ++i){
        int temp = rand() % (citys.size());
        while(arr[temp] == 1) temp =  rand() % (citys.size());
        arr[temp] = 1;
        isfull.insert(pair<string, int>(citys[temp], 0) );
        city_list.push_back(citys[temp]);
    }
    for_each(city_list.begin(), city_list.end(), write<string>);
    outfile<<endl;

    for(int i = 0; i < K; ++i){
        int temp = rand() % (city_list.size());
        while( isfull.find(city_list[temp])->second == (N-1) ) 
            temp = rand() % (city_list.size());
        isfull.find(city_list[temp])->second++;
        string now = city_list[temp];
        int temp2 = rand() % (city_list.size());
        while(now == city_list[temp2] || used.find(now+city_list[temp2]) != used.end() || used.find(city_list[temp2]+now) != used.end() ) temp2 = rand() % (city_list.size());
        int temp3 = rand() % (1000)+1;
        used.insert(pair<string, int>(now+city_list[temp2], 1) );
        used.insert(pair<string, int>(city_list[temp2]+now, 1) );
        isfull.find(city_list[temp2])->second++;
        outfile<<now<<" " << city_list[temp2] <<" "<<temp3<<endl;
    }

}