#include <iostream>
#include <stdlib.h>
#include <tuple>
#include <utility>
using namespace std;

typedef tuple<int, char, double, string> MyTuple;
typedef tuple<int, char> twoItemTuple;

int main(){
    pair<int, double> empty_pair;
    pair<int, char> pair1(1, 'p');
    MyTuple empty_tuple;
    MyTuple tuple1(1, 't', 0.5, "tuple");
    twoItemTuple pairT = pair1;
    cout<<"Empty Pair: "<<empty_pair.first <<"  "<<empty_pair.second<<endl;
    cout<<"Pair1: "<<pair1.first <<"  "<<pair1.second<<endl;
    cout<<"Empty Tuple: "<<"0:"<<get<0>(empty_tuple)<<"  1:"<<get<1>(empty_tuple)<<"  2:"
        <<get<2>(empty_tuple)<<"  3:"<<get<3>(empty_tuple)<<"  "<<endl;
    cout<<"Tuple1: "<<"0:"<<get<0>(tuple1)<<"  1:"<<get<1>(tuple1)<<"  2:"
        <<get<2>(tuple1)<<"  3:"<<get<3>(tuple1)<<"  "<<endl; 
    cout<<"Tuple from pair1: "<<get<0>(pairT)<<"  "<<get<1>(pairT)<<endl;
    
    return 0;
}