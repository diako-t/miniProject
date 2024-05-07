#include <iostream>
#include <string>
#include <iomanip>
using namespace std ;

class userpass
{
protected:
    string P_username = "ostad402" ;
    int P_password = 280011642 ;
    string username ;
    int password ;
    int s_username , s_password;
public:
   void set_Puserpass()
    {
        cout<<"enter username:\n";
        cin>>username ;
        cout<<"enter password:\n" ;
        cin>>password ;
    }
    void set_Suserpass()
    {
        cout<<"enter username:\n";
        cin>>s_username ;
        cout<<"enter password:\n" ;
        cin>>s_password ;
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
    void change_up(string a , int b)
    {
        P_username = a ;
        P_password = b ;
    }
};

//--------------------------------------------------------------------------------

class exam
{
protected:
    int d_counter = 1 , t_counter = 1 ;
    int m = 1 , time , type ;
    float * d_grade = new float [d_counter] ;
    float * t_grade = new float [t_counter] ;
    string * descriptive = new string [d_counter] ;
    string * test = new string [t_counter] ;
    string ** options =(string **) new string[t_counter][4] ;
    int * correctAnswer = new int [t_counter] ;
    int list_n = -1;
public:
    void questionType()
    {
        cout<<"which type of question you want to enter?\n"<<"1_descriptive  or  2_test "<<"(press 0 if you are done)\n" ;
        cin>>type ;
        if(type == 1)
            descriptiveQuestion() ;
        else if(type == 2)
            testQuestion() ;
        else
            details() ;
    }
    void testQuestion()
    {
        cout<<"enter question number "<<m<<endl ;
        getline(cin , test[t_counter-1]) ;
        cout<<"enter 4 options (press enter after each option)\n" ;
        for(int i=0 ; i<4 ; i++)
            getline(cin , options[t_counter-1][i]) ;
        cout<<"which answer is correct?\n" ;
        cin>>correctAnswer[t_counter-1] ;
        cout<<"score for this question:\n" ;
        cin>>t_grade[t_counter-1];
        t_counter++ ;
        m++ ;
        questionType() ;
    }
    void descriptiveQuestion()
    {
        d_counter++ ;
        m++ ;
        cout<<"enter question number "<<m<<endl ;
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
    void setList_n(int y)
    {
        list_n = y;
    }
    int retList_n()
    {
        return list_n;
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
};

//-------------------------------------------------------------------------------------

class correction :public exam
{
    int user , pass , exam_number;
public:
    void set_data(int u , int p , int e)
    {
        user = u;
        pass = p;
        exam_number = e;
    }
};

//-------------------------------------------------------------------------------------

class list
{
protected:
    int size = 0 ;
    int * s_username = new int [size] ;
    int * s_password = new int [size] ;
public:
    void make_list()
    {
        int order = 1 ;
        while (order==1)
        {
            size++ ;
            cout << "enter student " << size << " username(student ID) and password(national ID number)\n";
            cin >> s_username[size - 1] >> s_password[size - 1];
            cout << "press 1 if you want to continue or press 2 if you are done\n";
            cin >> order;

        }
    }
    void add_student()
    {
        int order = 1;
        while (order==1) {
            size++ ;
            cout << "enter student " << size << " username(student ID) and password(national ID number)\n";
            cin >> s_username[size - 1] >> s_password[size - 1];
            cout << "press 1 if you want to continue or press 2 if you are done\n";
            cin >> order;
        }
    }
    void remove_student()
    {
        int temp , order = 1 , user;
        while(order==1)
        {
            cout<<"student username:\n" ;
            cin>>user ;
       for(int i=0 ; i<size ; i++)
       {
           temp = s_username[i] ;
           if(user == temp)
           {
               for (int j = i; j < size - 1; j++)
                   s_username[j] = s_username[j + 1];
               for (int j = i; j < size - 1; j++)
                   s_password[j] = s_password[j + 1];
               size-- ;
               break ;
           }
       }
       cout<<"press 1 if you want to continue or press 2 if you are done\n";
       cin>>order ;
    }
    }
    void print_lists()
    {
        for (int i = 0; i < size; ++i)
            cout<<s_username<<setw(3)<<s_password<<endl;
    }
    int ret_username(int x)
    {
        return s_username[x];
    }
    int ret_password(int x)
    {
        return s_password[x];
    }
    int ret_n()
    {
        return size;
    }
    ~list()
    {
        delete[]s_username ;
        delete[]s_password ;
    }
};

//--------------------------------------------------------------------------------

class professor : public userpass
{
protected:
    int n , new_pass , exam_counter = 0 , list_counter = 0 , cor_counter = 0 , number;
    string new_user;
    exam * ex = new exam [exam_counter];
    list * li = new list [list_counter];
    correction * cor = new correction [cor_counter];
public:
    void order() {
        do {
            cout << "1_change usrename and password\n2_make an exam\n3_show exams\n4_Number of available exams\n";
            cout << "5_make a student list\n6_Number of available lists\n7_show lists\n8_add and remove student from a list\n";
            cout<<"9_add a student list to an exam\n";
            cout << "0_exit\n";
            cin >> n;
            switch (n) {
                case 1:
                    cout << "enter new username:\n";
                    cin >> new_user;
                    cout << "enter new password\n";
                    cin >> new_pass;
                    change_up(new_user, new_pass);
                    break;
                case 2:
                    exam_counter++;
                    ex[exam_counter - 1].questionType();
                    break;
                case 3:
                    cout << "exam number :\n";
                    cin >> number;
                    ex[number - 1].print_questions();
                    break;
                case 4:
                    cout << exam_counter << " exams\n";
                    break;
                case 5:
                    list_counter++;
                    li[list_counter - 1].make_list();
                    break;
                case 6:
                    cout << list_counter << " student lists\n";
                    break;
                case 7:
                    cout << "list number :\n";
                    cin >> number;
                    li[number - 1].print_lists();
                    break;
                case 8:
                    int num;
                    cout << "list number :\n";
                    cin >> number;
                    cout << "1_add or 2_remove student from list\n";
                    cin >> num;
                    if (num == 1)
                        li[number - 1].add_student();
                    else
                        li[number - 1].remove_student();
                    break;
                case 9:
                    int l , e;
                    cout<<"list number: ";
                    cin>>l;
                    cout<<"\nto exam number: ";
                    cin>>e;
                    ex[e - 1].setList_n(l-1);
                    break;
            }
        } while (n != 0) ;
    }
    void student_answer(int a , int b , int c)
    {
        cor_counter++;
        cor[cor_counter-1].set_data(a , b , c);
    }
};
//---------------------------------------------------------------------
class student : public professor
{
    int list_number , index;
public:
    bool s_check()
    {
        bool flag = false;
        int size;
        set_Suserpass();
        for(int i=0 ; i<list_counter ; i++) {
            size = li[i].ret_n();
            for (int j=0 ; j<size ; j++)
                if (s_username == li[i].ret_username(j))
                    if (s_password == li[i].ret_password(j)) {
                        cout << "welcome student " << s_username << endl;
                        flag = true ;
                        break;
                    }
            if(flag) {
                list_number = i ;
                break;
            }
        }
        if(!flag)
            cout<<"wrong information!\n";
        return flag;
    }
    void s_order()
    {
        int d ;
        bool find = false;
        cout<<"1_start exam\n2_see score\n";
        cin>>d;
        if(d == 1) {
            for (int i = 0; i < exam_counter; i++)
                if (ex[i].retList_n() == list_number) {
                    ex[i].print_questions();
                    index = i;
                    find = true;
                    break;
                }
            if(!find)
                cout<<"no exam found for you!\n";
            else
                student_answer(s_username , s_password , index);
        }
    }
};

//---------------------------------------------------------------------------------

int main()
{
    student ob;
    int n ;
    cout<<"log in as : 1_professor  or  2_student\n" ;
    cin>>n ;
    if(n == 1) {
        ob.set_Puserpass();
        if (ob.P_check())
            ob.order();
    }
    else
    {
        if(ob.s_check())
            ob.s_order();

    }
    return 0 ;
}