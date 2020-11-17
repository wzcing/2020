#include<iostream>
using namespace std;

int main(){
    cout<<"input number and operator"<<endl;
    float a;
    float b;
    char c;
    cin>>a>>c>>b;
    if(b==0&&c=='/'){
        cout<<"your input is invalid"<<endl;
        return 0;
    }
    switch(c){
        case '+':
            cout<<a+b<<endl;
            break;
        case '-':
            cout<<a-b<<endl;
            break;
        case '*':
            cout<<a*b<<endl;
            break;
        case '/':
            cout<<a/b<<endl;
            break;
        default:
            cout<<"your input is invalid"<<endl;

    }
    return 0;
}