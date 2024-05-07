#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
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
    int d_counter = 0 , t_counter = 0 ;
    int time , type ;
    string * descriptive ;
    string *helper_descriptive;
    float * d_grade ;
    float *d_grade_helper;
    string * test;
    string * helper_test;
    float * t_grade;
    float * t_grade_helper;
    string * options;
    string * options_helper;
    int * correctAnswer;
    int * correctAnswer_helper;
    int list_n = -1;
    bool d_check = false;
    bool t_check = false;
public:
    void questionType()
    {
        cout<<"which type of question you want to enter?\n"<<"1_descriptive  or  2_test "<<"(press 0 if you are done)\n" ;
        cin>>type ;
        if(type == 1) {
            descriptiveQuestion();
        }
        else if(type == 2)
            testQuestion() ;
        else
            details() ;
    }
    void testQuestion() {
        if (!t_check) {
            t_counter++;
            test = new string[t_counter];
            cout << "your question?\n";
            getline(cin >> ws, test[t_counter - 1]);
            options = new string [t_counter*4];
            cout << "enter 4 options (press enter after each one)\n";
            for(int i=0 ; i<(t_counter*4) ; i++)
                getline(cin>>ws , options[i]);
            correctAnswer = new int[t_counter];
            cout << "which answer is correct ?\n";
            cin >> correctAnswer[t_counter - 1];
            t_grade = new float[t_counter];
            cout << "score for this question:\n";
            cin >> t_grade[t_counter - 1];
        }
        else {
            helper_test = new string[t_counter];
            options_helper = new string[t_counter*4];
            correctAnswer_helper = new int [t_counter];
            t_grade_helper = new float [t_counter] ;
            for (int i = 0; i < t_counter; ++i)
            {
                helper_test[i] = test[i] ;
                correctAnswer_helper[i] = correctAnswer[i];
                t_grade_helper[i] = t_grade[i];
            }
            for(int i = 0; i < (t_counter*4); ++i)
                options_helper[i] = options[i];
            delete[]test;
            delete[]options;
            delete[]correctAnswer;
            delete[]t_grade;
            t_counter++;
            test = new string[t_counter];
            options = new string[t_counter*4];
            correctAnswer = new int[t_counter];
            t_grade = new float[t_counter];
            for (int i = 0; i < (t_counter-1); ++i)
            {
                test[i] = helper_test[i];
                correctAnswer[i] = correctAnswer_helper[i];
                t_grade[i] = t_grade_helper[i];
            }
            for (int i = 0; i < ((t_counter*4)-4); ++i)
                options[i] = options_helper[i];
            delete[]helper_test;
            delete[]options_helper;
            delete[]correctAnswer_helper;
            delete[]t_grade_helper;
            cout << "your question?\n";
            getline(cin >> ws, test[t_counter - 1]);
            cout << "enter 4 options (press enter after each one)\n";
            for (int i = ((t_counter*4)-4); i < (t_counter*4); i++)
                getline(cin >> ws, options[i]);
            cout << "which answer is correct ?\n";
            cin >> correctAnswer[t_counter - 1];
            cout << "score for this question:\n";
            cin >> t_grade[t_counter - 1];
        }
        t_check = true;
        questionType();
    }
    void descriptiveQuestion()
    {
        if(!d_check)
        {
            d_counter++ ;
            descriptive = new string [d_counter];
            cout<<"your question?\n";
            getline(cin>>ws , descriptive[d_counter-1]) ;
            d_grade = new float [d_counter];
            cout<<"score for this question:\n" ;
            cin>>d_grade[d_counter-1] ;
        }
        else
        {
            d_grade_helper = new float [d_counter];
            helper_descriptive = new string [d_counter];
            for (int i = 0; i < d_counter; ++i)
            {
                helper_descriptive [i] = descriptive[i];
                d_grade_helper[i] = d_grade[i];
            }
            delete [] descriptive;
            delete [] d_grade;
            ++d_counter;
            d_grade = new float [d_counter];
            descriptive = new string [d_counter];
            for (int i = 0; i < (d_counter-1); ++i)
            {
                descriptive[i] = helper_descriptive[i];
                d_grade [i] = d_grade_helper[i];
            }
            delete [] helper_descriptive;
            delete [] d_grade_helper;
            cout<<"your question?\n";
            getline(cin>>ws , descriptive[d_counter-1]) ;
            cout<<"score for this question:\n" ;
            cin>>d_grade[d_counter-1] ;
        }
        d_check = true;
        questionType();
    }
    void details()
    {
        int order ;
        float sum = 0 ;
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
        int counter = 0 , w = 0;
        char abcd[4] = {'A' , 'B' , 'C' , 'D'};
        cout<<"descriptive questions:\n" ;
        for(int i=0 ; i<d_counter ; i++)
            cout<<i+1<<"- "<<descriptive[i]<<"( "<<d_grade[i]<<" )"<<endl;
        cout<<"test questions:\n" ;
        for(int j=0 ; j<t_counter ; j++) {
            cout<<(d_counter+j+1)<<"- "<<test[j]<<"( "<<t_grade[j]<<" )"<<endl;
            for (int i = (counter * 4); i < ((counter * 4) + 4); i++) {

                cout<<abcd[w]<<"_ "<<options[i]<<endl;
                w++;
            }
            counter++;
            w = 0;
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
    int retD_counter()
    {
        return d_counter;
    }
    int retT_counter()
    {
        return t_counter;
    }
    float retD_grade(int x)
    {
        return d_grade[x];
    }
    float retT_grade(int x)
    {
        return t_grade[x];
    }
    int ret_correct(int x)
    {
        return correctAnswer[x];
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

class correction
{
    int user , pass , exam_number ;
    
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
    vector<int>s_username;
    vector<int>s_password;
    int username , password ;
public:
    void make_list()
    {
        int order = 1 ;
        while (order==1)
        {
            cout << "enter student " << s_username.size() +1 << " username(student ID) and password(national ID number)\n";
            cin >>username>>password;
            s_username.push_back(username);
            s_password.push_back(password);
            cout << "press 1 if you want to continue or press 2 if you are done\n";
            cin >> order;

        }
    }
    void remove_student()
    {
        int temp ;
        int order = 1;
        while(order==1)
        {
            cout << "enter student username:" << endl;
            cin >> temp;
            auto x = find(s_username.begin() , s_username.end() , temp);
            if(x != s_username.end())
                s_username.erase(x);
            else
                cout << "not found" << endl;
       cout<<"press 1 if you want to continue or press 2 if you are done\n";
       cin>>order ;
    }
    }
    void print_lists()
    {
        cout<<"username:        password:\n";
        for (int i = 0; i < s_username.size() ; ++i)
            cout<<s_username[i]<<"              "<<s_password[i]<<endl;
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
        return s_username.size() +1;
    }
};

//--------------------------------------------------------------------------------

class professor : public userpass
{
protected:
    int n , new_pass , exam_counter = 0 , list_counter = 0 , cor_counter = 0 , number;
    string new_user;
    exam * ex;
    exam * ex_helper;
    bool ex_check = false;
    list * li;
    list * li_helper;
    bool li_check = false;
    correction * cor;
    correction * cor_helper;
    bool cor_check = false;
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
                    if(!ex_check)
                    {
                        exam_counter++;
                        ex = new exam [exam_counter];
                        ex[exam_counter-1].questionType();
                    }
                    else
                    {
                        ex_helper = new exam [exam_counter];
                        for(int i=0 ; i<exam_counter ; i++)
                            ex_helper[i] = ex[i];
                        //delete [] ex; ????
                        exam_counter++;
                        ex = new exam[exam_counter];
                        for(int j=0 ; j<(exam_counter-1) ; j++)
                            ex[j] = ex_helper[j];
                        //delete[]ex_helper; ????
                        ex[exam_counter-1].questionType();
                    }
                    ex_check = true;
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
                    if(!li_check)
                    {
                        list_counter++;
                        li = new list [list_counter];
                        li[list_counter-1].make_list();
                    }
                    else
                    {
                        li_helper = new list [list_counter];
                        for(int i=0 ; i<list_counter ; i++)
                            li_helper[i] = li[i];
                        delete[]li;
                        list_counter++;
                        li = new list[list_counter];
                        for(int j=0 ; j<(list_counter-1) ; j++)
                            li[j] = li_helper[j];
                        delete[]li_helper;
                        li[list_counter-1].make_list();
                    }
                    li_check = true;
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
                        li[number - 1].make_list();
                    else
                        li[number - 1].remove_student();
                    break;
                case 9:
                    int l , e;
                    cout<<"list number:\n";
                    cin>>l;
                    cout<<"to exam number:\n";
                    cin>>e;
                    ex[e - 1].setList_n(l-1);
                    break;
            }
        } while (n != 0) ;
    }
    void student_answer(int a , int b , int c)
    {
        if(!cor_check)
        {
            cor_counter++;
            cor = new correction[cor_counter];
            cor[cor_counter-1].set_data(a , b , c);
        }
        else
        {
            cor_helper = new correction[cor_counter];
            for(int i=0 ; i<cor_counter ; i++)
                cor_helper[i] = cor[i];
            delete[]cor;
            cor_counter++;
            cor = new correction[cor_counter];
            for(int j=0 ; j<(cor_counter-1); j++)
                cor[j] = cor_helper[j];
            delete[]cor_helper;
            cor[cor_counter-1].set_data(a , b , c);
        }
        cor_check = true;
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
            else {
                student_answer(s_username, s_password, index);
            }
        }
    }
};

//---------------------------------------------------------------------------------

int main()
{
    student ob;
    int n ;
    cout << "log in as : 1_professor  or  2_student\n";
    cin >> n;
    while(n == 1 || n == 2)
    {
        if (n == 1) {
            ob.set_Puserpass();
            if (ob.P_check())
                ob.order();
        }
        else {
            if (ob.s_check())
                ob.s_order();
        }
        cout << "log in as : 1_professor  or  2_student\n";
        cin >> n;
    }
    return 0 ;
}