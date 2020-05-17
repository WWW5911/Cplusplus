#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

class stundent{
    public:
    string name;
    int english;
    int math;
    stundent(): name(""), english(0), math(0){}
    friend ostream &operator<<(ostream &s, stundent st){
        s<<st.name<<" " <<st.english << " " << st.math;
        return s;
    }
    friend istream & operator>>(istream &s, stundent &st){
        s>>st.name>>st.english >> st.math;
        return s;
    }
    friend bool operator< ( stundent const& S1, stundent const& S2){
        if( (S1.english + S1.math) < (S2.english + S2.math) ) return true;
        if( (S1.english + S1.math) == (S2.english + S2.math) )
            if(S1.name < S2.name) return true;
        return false;
    }
};

class RuntimeCmp{
    public:
        enum cmp_mode{n,r};
        cmp_mode mode;
        RuntimeCmp(cmp_mode m = n) : mode(m){}
        template <typename T>
        bool operator()(const T& t1, const T& t2){
            return mode == n ? t1<t2 : t2<t1;
        }
        bool operator==(const RuntimeCmp & rc){
            return mode == rc.mode;
        }
};
template<typename T>
void print(T node){
    cout<<node<<endl;
}

int main(){
    set<stundent , RuntimeCmp> set1(RuntimeCmp::n);
    set<stundent , RuntimeCmp> set2(RuntimeCmp::r);
    int n = 0;
    cin>>n;
    for(int i = 0; i < n; ++i){
        stundent temp;
        cin>>temp;
        set1.insert(temp);
        set2.insert(temp);
    }
    cout<<"Set A:"<<endl;
    for_each(set1.begin(), set1.end(), print<stundent>);

    cout<<endl<<"Set B:"<<endl;
    for_each(set2.begin(), set2.end(), print<stundent>);
}