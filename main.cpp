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

//--------------------------------------------------------------------------------

class exam
{
    static int e_counter;
protected:
    int d_counter = 0 , t_counter = 0 ;
    int n = 0 , time , type ;
    int * d_grade = new int [d_counter] ;
    int * t_grade = new int [t_counter] ;
    string * descriptive = new string [d_counter] ;
    string * test = new string [t_counter] ;
    string ** options =(string **) new string[t_counter][4] ;
    int * correctAnswer = new int [t_counter] ;
public:
    void questionType()
    {
        e_counter++ ;
        cout<<"which type of question you want to enter?\n"<<"1_descriptive  or  2_test "<<"(press 0 if you are done)\n" ;
        cin>>type ;
        if(type == 1)
            descriptiveQuestion() ;
        else if(type == 2)
            testQuestionًً() ;
        else
            details() ;
    }
    void testQuestionًً()
    {
        t_counter++ ;
        n++ ;
        cout<<"enter question number "<<n<<endl ;
        getline(cin , test[t_counter-1]) ;
        cout<<"enter 4 options (press enter after each option)\n" ;
        for(int i=0 ; i<4 ; i++)
            getline(cin , options[t_counter-1][i]) ;
        cout<<"which answer is correct?\n" ;
        cin>>correctAnswer[t_counter-1] ;
        cout<<"score for this question:\n" ;
        cin>>t_grade[t_counter-1];
        questionType() ;
    }
    void descriptiveQuestion()
    {
        d_counter++ ;
        n++ ;
        cout<<"enter question number "<<n<<endl ;
        getline(cin , descriptive[d_counter-1]) ;
        cout<<"score for this question:\n" ;
        cin>>d_grade[d_counter-1] ;
        questionType() ;
    }
    void details()
    {
        int order ;
        int sum = 0 ;
        cout<<"time to answer exam:\n" ;
        cin>>time ;
        cout<<"press 1 if you want to see the details of exam or press 2 if you want to save the exam and exit\n" ;
        cin>>order ;
        if(order == 1)
        {
            cout<<t_counter<<" test questions\n"<<d_counter<<" descriptive questions\n" ;
            for(int j=0 ; j<d_counter ; j++)
                sum += d_grade[j];
            for(int j=0 ; j<t_counter ; j++)
                sum += t_grade[j];
            cout<<"total grade: "<<sum<<endl<<"total time: "<<time<<endl ;
        }
        else
            cout<<"exam saved\n" ;
    }
    static void count_print()
    {
        cout<<e_counter;
    }
    void print_questions()
    {
        cout<<"descriptive questions:\n" ;
        for(int i=0 ; i<d_counter ; i++)
            cout<<i+1<<"- "<<descriptive[i]<<"( "<<d_grade[i]<<" )"<<endl;
        cout<<"test questions:\n" ;
        for(int i=0 ; i<t_counter ; i++)
            {
            cout<<(d_counter+i+1)<<"- "<<test[i]<<"( "<<t_grade[i]<<" )"<<endl;
            cout<<"A_ "<<options[i][1]<<endl<<"B- "<<options[i][2]<<endl<<"C_ "<<options[i][3]<<endl<<"D_ "<<options[i][4]<<endl;
            }
        cout<<"time(minute) = "<<time<<endl<<"good luck"<<endl;
    }

    ~exam()
    {
        delete[]d_grade;
        delete[]t_grade;
        delete[]descriptive;
        delete[]test;
        delete[]correctAnswer;
        delete[]options;
    }
}; int exam::e_counter = 0;

//-------------------------------------------------------------------------------------

class list
{
    static int l_counter;
protected:
    int n = 0 ;
    int * s_username = new int [n] ;
    int * s_password = new int [n] ;
public:
    void make_list()
    {
        l_counter++ ;
        int order = 1 ;
        while (order==1)
        {
            n++;
            cout << "enter student " << n << " username(student ID) and password(national ID number)\n";
            cin >> s_username[n - 1] >> s_password[n - 1];
            cout << "press 1 if you want to continue or press 2 if you are done\n";
            cin >> order;

        }
    }
    void add_student()
    {
          n++;
          cout << "enter student " << n << " username(student ID) and password(national ID number)\n";
          cin >> s_username[n - 1] >> s_password[n - 1];
    }
    void remove_student()
    {
        int temp , order = 1 , user;
        while(order==1)
        {
            cout<<"student username:\n" ;
            cin>>user ;
       for(int i=0 ; i<n ; i++)
       {
           temp = s_username[i] ;
           if(user == temp)
           {
               for (int j = i; j < n - 1; j++)
                   s_username[j] = s_username[j + 1];
               for (int j = i; j < n - 1; j++)
                   s_password[j] = s_password[j + 1];
               n-- ;
               break ;
           }
       }
       cout<<"press 1 if you want to continue or press 2 if you are done\n";
       cin>>order ;
    }
    }
    static void count_print()
    {
        cout<<l_counter;
    }
    ~list()
    {
        delete[]s_username ;
        delete[]s_password ;
    }
}; int list::l_counter = 0;

//--------------------------------------------------------------------------------

class professor
{

};

class student
{

};

//---------------------------------------------------------------------------------

int main()
{
    int n ;
    cout<<"log in as : 1_professor  or  2_student\n" ;
    cin>>n ;
    userpass u1 ;
    if(n == 1) {
        if (u1.P_check())
            professor p1;
    }
        else {
        if (u1.S_check())
            student s1;
    }
    return 0 ;
}