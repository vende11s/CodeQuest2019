#include <iostream>
#include <array>

using namespace std;

int main(){

    int n;
    cin>>n;

    while(n--){
        int n;
        string s;

        cin>>n>>s;

        array<int, 2> tickets = {60, 80};

        if(s == "true"){
            tickets[0] += 5;
            tickets[1] +=5;
        }

        if(n <= tickets[0]){
            cout<<"no ticket"<<endl;
        } else if(n <= tickets[1]){
            cout<<"small ticket"<<endl;
        } else {
            cout<<"big ticket"<<endl;
        }

    }

}
