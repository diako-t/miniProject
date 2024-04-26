#include <iostream>
#include <string>
using namespace std ;

class userpass
{
protected:
    string P_username = "ostad402" ;
    int P_password = 280011642 ;
    string username ;
    int password ;
public:
    userpass()
    {
        cout<<"enter username:\n";
        cin>>username ;
        cout<<"enter password:\n" ;
        cin>>password ;
    }
    bool P_check()
    {
        if((username == P_username) && (password == P_password)) {
            cout << "welcome " << P_username << endl;
            return true ;
        }
        else {
            cout << "wrong information\n";
            return false;
        }

    }
    bool S_check()
    {
    }
    void change_up(string a , int b)
    {
        P_username = a ;
        P_password = b ;
    }
};

class professor
{

};

class student
{

};

int main()
{
    int n ;
    cout<<"log in as : 1_professor  or  2_student\n" ;
    cin>>n ;
    userpass u1 ;
    if(n == 1)
        if(u1.P_check())
            professor p1 ;
    else
        if(u1.S_check())
            student s1 ;
}