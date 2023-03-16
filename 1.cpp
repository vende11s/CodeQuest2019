#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    string s;
    getline(cin, s);

    while(n--){
        getline(cin, s);

        for(auto &e : s){
            if(e >= 'A' && e <='Z'){
                e+=32;
            }
        }

        cout<<s<<endl;
    }

}
