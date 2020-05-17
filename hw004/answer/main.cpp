#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Edge{
    public:
    string p1, p2;
    int cost;
    Edge(){}
    Edge(string pp, string ppp, int c){
        p1 = pp;
        p2 = ppp;
        cost = c;
    }
    friend bool operator<(Edge& a, Edge& b){
        return a.cost > b.cost;
    }
    friend istream & operator>>(istream &s, Edge &p){
        s>>p.p1>>p.p2>>p.cost;
        return s;
    }
};
string find(map<string, string> disjoin, string str){
    while(disjoin.find(str)->second != "-1"){
        str = disjoin.find(str)->second;
    }
    return str;
}
int main(){

    int n = 0, k = 0, count = 0, ans = 0;
    vector<string> city;
    vector<Edge> edge;
    map<string, string> disjoin;
    bool flag = false;
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        string temp = "";
        cin >> temp;
        city.push_back(temp);
        disjoin.insert(pair<string, string>(temp, "-1"));
    }
    for (int i = 0; i < k; ++i){
        Edge temp;
        cin >> temp;
        edge.push_back(temp);
    }
    sort(edge.begin(), edge.end());
    while (count < n - 1){
        Edge temp = edge[edge.size() - 1];
        edge.pop_back();
        if (find(disjoin, temp.p1) != find(disjoin, temp.p2)){
            count++;
            disjoin[temp.p2] = find(disjoin, temp.p1);
            ans += temp.cost;
        }
        if (edge.size() == 0 && count != n - 1){
            flag = true;
            break;
        }
    }
    if (!flag) cout << ans << endl;
    else cout << "-1" << endl;
}