#include <iostream>
#include <cassert>
#include "vector.cpp"

using namespace std;
using namespace UTEC;

int main() {

    vector v1;
    assert(v1.size()==0);


    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    cout <<"Push Back" <<endl;
    for(int i=0; i<v1.size();i++){
        cout << v1[i] << endl;
    }
    cout<<"\n";
    assert(v1.size()==4);


    v1.pop_back();
    assert(v1.size()==3);
    cout <<"Pop Back" <<endl;
    for(int i=0; i<v1.size();i++){
        cout << v1[i] << endl;
    }
    cout<<"\n";


    v1.insert(40,2);
    assert(v1.size()==4);
    cout <<"Insert" <<endl;
    for(int i=0; i<v1.size();i++){
        cout << v1[i] << endl;
    }
    cout<<"\n";


    v1.erase(1);
    assert(v1.size()==3);
    cout <<"Erase" <<endl;
    for(int i=0; i<v1.size();i++){
        cout << v1[i] << endl;
    }
    cout<<"\n";

    vector v2;
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    vector v3;
    v3 = v1+v2;
    cout <<"Concatenar" <<endl;
    for(int i=0; i<v3.size();i++){
        cout << v3[i] << endl;
    }


    int total = 0;
    for(int i=0; i<v1.size();i++){
        total += v1[i];
    }
    cout << "El total es: " << total;
    cout<<"\n";
    assert(total==100);

return 0;
}