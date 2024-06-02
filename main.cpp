#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include <ctime>
using namespace std ;

class userpass
{
protected:
    string P_username = "ostad402";
    int P_password = 280011642;
    string username;
    int password;
    int s_username , s_password;
public:
   void get_Puserpass()
    {
        cout<<"enter username:\n";
        cin>>username ;
        cout<<"enter password:\n";
        cin>>password ;
    }
    void get_Suserpass()
    {
        cout<<"enter username:\n";
        cin>>s_username ;
        cout<<"enter password:\n";
        cin>>s_password ;
    }
    bool P_check()
    {
        if((username == P_username) && (password == P_password)) {
            cout << "welcome " << P_username << endl;
            return true;
        }
        else {
            cout << "wrong information\n";
            return false;
        }

    }
    void change_up(string a , int b)
    {
        P_username = a;
        P_password = b;
        cout<<"changed seccesfully!\n";
    }
};

//--------------------------------------------------------------------------------

class exam
{
protected:
    int type , time;
    vector<string>test;
    string temp;
    vector<string>options;
    vector<int>correctAnswer;
    int i_temp;
    vector<float>t_grade;
    float f_temp;
    vector<string>descriptive;
    vector<float>d_grade;
    vector<int>list_number;
    int share = -1 ;
public:
    void questionType()
    {
        cout<<"which type of question you want to enter?\n"<<"1_descriptive  or  2_test "<<"(press 0 if you are done)\n";
        cin>>type;
        if(type == 1) {
            descriptiveQuestion();
        }
        else if(type == 2)
            testQuestion();
        else if(type == 0)
            details();
        else {
            cout << "invalid number!\n";
            back();
        }
    }
    void testQuestion() {
            cout << "your question?\n";
            getline(cin >> ws, temp);
            test.push_back(temp);
            cout << "enter 4 options (press enter after each one)\n";
            for(int i=0 ; i<4 ; i++) {
                getline(cin >> ws, temp);
                options.push_back(temp);
            }
            cout << "which answer is correct ?\n";
            cin >> i_temp;
            correctAnswer.push_back(i_temp);
            cout << "score for this question:\n";
            cin >> f_temp;
            t_grade.push_back(f_temp);
            questionType();
    }
    void descriptiveQuestion()
    {
            cout<<"your question?\n";
            getline(cin>>ws , temp);
            descriptive.push_back(temp);
            cout<<"score for this question:\n";
            cin>>f_temp;
            d_grade.push_back(f_temp);
            questionType();
    }
    void details()
    {
        int order;
        float sum = 0;
        cout<<"time to answer exam: ";
        cin>>time;
        cout<<"press 1 if you want to see the details of exam or press 2 if you want to save the exam and exit\n";
        cin>>order;
        if(order == 1)
        {
            cout<<test.size()<<" test questions\n"<<descriptive.size()<<" descriptive questions\n";
            for(int j=0 ; j<d_grade.size() ; j++)
                sum += d_grade[j];
            for(int j=0 ; j<t_grade.size() ; j++)
                sum += t_grade[j];
            cout<<"total grade: "<<sum<<endl<<"total time: "<<time<<endl;
        }
        else
            cout<<"exam saved\n";
    }
    void back()
    {
        questionType();
    }
    void print_questions()
    {
        int counter = 0 , w = 0;
        char abcd[4] = {'A' , 'B' , 'C' , 'D'};
        if(!descriptive.empty()) {
            cout << "descriptive questions:\n";
            for (int i = 0; i < descriptive.size(); i++)
                cout << i + 1 << "- " << descriptive[i] << "( " << d_grade[i] << " )" << endl;
        }
        if(!test.empty()) {
            cout << "test questions:\n";
            for (int j = 0; j < test.size(); j++) {
                cout << (descriptive.size() + j + 1) << "- " << test[j] << "( " << t_grade[j] << " )" << endl;
                for (int i = (counter * 4); i < ((counter * 4) + 4); i++) {

                    cout << abcd[w] << "_ " << options[i] << endl;
                    w++;
                }
                counter++;
                w = 0;
            }
        }
        cout<<"time(minute) = "<<time<<endl<<"good luck"<<endl;
    }
    void sharing(int s)
    {
        if(s == 1)
            share = 0;
        else if(s == 2)
            share = 1;
    }
    bool ret_share()
    {
        return share;
    }
    void setList_n(int y)
    {
        list_number.push_back(y);
    }
    int retList_n(int i)
    {
        return list_number[i];
    }
    int retListSize()
    {
        return list_number.size();
    }
    int retD_counter()
    {
        return descriptive.size();
    }
    int retT_counter()
    {
        return test.size();
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
    int ret_time()
    {
        return time;
    }
};

//-------------------------------------------------------------------------------------

class correction
{
    int user , pass , exam_number , ti;
    int d_counter , t_counter;
    float total_grade = 0;
    float * d_grade;
    float * t_grade;
    int * correctAnswer;
    string * d_answer;
    int * t_answer;
    string * WR_answers;
    float * student_grade;
    string * comment;
    bool check = false;
public:
    void set_data(int u , int p , int e , int t)
    {
        user = u;
        pass = p;
        exam_number = e;
        ti = t;
    }
    void set_counter(int d , int t)
    {
        d_counter = d;
        t_counter = t;
        d_grade = new float [d_counter];
        student_grade = new float [d_counter];
        d_answer = new string [d_counter];
        comment = new string [d_counter];
        t_grade = new float [t_counter];
        correctAnswer = new int [t_counter];
        t_answer = new int [t_counter];
        WR_answers = new string [t_counter];
        for(int i=0 ; i<d_counter ; i++)
            d_answer[i] = "not answered";
        for(int j=0 ; j<t_counter ; j++)
            t_answer[j] = '0';
    }
    void set_Dgrade(int x , float g)
    {
        d_grade[x] = g;
    }
    void set_Tgrade(int x , float g , int c)
    {
        t_grade[x] = g;
        correctAnswer[x] = c;
    }
    void get_answers()
    {
        int m = 0 , hour = 0 , min = 0 , sec = 0;
        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout << "current time " << ltm->tm_hour <<":"<< ltm->tm_min <<":"<< ltm->tm_sec << endl;
        int additionalhours = ti / 60;
        int additionalminutes = ti % 60;
        ltm->tm_min += additionalminutes;
        if(ltm->tm_min >= 60)
        {
            ltm->tm_min -= 60;
            additionalhours++;
        }
        ltm->tm_hour = (ltm->tm_hour + additionalhours) % 24;
        cout << "exam finished at " << ltm->tm_hour <<":"<< ltm->tm_min <<":"<< ltm->tm_sec << endl;
        hour = ltm->tm_hour;
        min = ltm->tm_min;
        sec = ltm->tm_sec;
        if(d_counter != 0) {
            cout << "descriptive answers:\n";
            for (int j = 0; j < d_counter; j++) {
                time_t now = time(0);
                tm *ltm = localtime(&now);
                if(ltm->tm_hour > hour){
                    cout << "your time is up" << endl;
                    return;
                }
                else if(ltm->tm_hour < hour)
                {
                    cout << "";
                }
                else if(ltm->tm_hour == hour) {
                    if (ltm->tm_min > min) {
                        cout << "your time is up" << endl;
                        return;
                    }
                    else if(ltm->tm_min < min) {
                        cout << "";
                    }
                    else if (ltm->tm_min == min ) {

                        if(ltm->tm_sec < sec) {
                            cout << "";
                        }
                        else if(ltm->tm_sec >= sec)
                        {
                            cout << "your time is up" << endl;
                            return;
                        }
                    }
                }
                m++;
                cout << m << "_ ";
                getline(cin >> ws, d_answer[j]);
            }
        }
        if(t_counter != 0) {
            cout << "test answers(number of correct option only):\n";
            m = 0;
            for (int j = 0; j < t_counter; j++) {
                time_t now = time(0);
                tm *ltm = localtime(&now);
                if(ltm->tm_hour > hour){
                    cout << "your time is up" << endl;
                    return;
                }
                else if(ltm->tm_hour < hour)
                {
                    cout << "";
                }
                else if(ltm->tm_hour == hour) {
                    if (ltm->tm_min > min) {
                        cout << "your time is up" << endl;
                        return;
                    }
                    else if(ltm->tm_min < min) {
                        cout << "";
                    }
                    else if (ltm->tm_min == min ) {

                        if(ltm->tm_sec < sec) {
                            cout << "";
                        }
                        else if(ltm->tm_sec >= sec)
                        {
                            cout << "your time is up" << endl;
                            return;
                        }
                    }
                }
                m++;
                cout << m << "_ ";
                cin >> t_answer[j];
            }
        }
    }
    void test_correction()
    {
        for(int i=0 ; i<t_counter ; i++)
        {
            if(t_answer[i] == correctAnswer[i])
            {
                total_grade += t_grade[i];
                WR_answers[i] = "right answer";
            }
            else
                WR_answers[i] = "wrong answer";
        }
    }
    void descriptive_correction()
    {
        check = true;
        int z;
        if(d_counter != 0) {
            for (int j = 0; j < d_counter; j++) {
                cout << j + 1 << "_ " << d_answer[j] << endl;
                cout << "(" << d_grade[j] << ")" << endl << "student's grade:";
                cin >> student_grade[j];
                cout << "do you want to add comment for this answer? 1_yes  2_no\n";
                cin >> z;
                if (z == 1)
                    getline(cin >> ws, comment[j]);
                else
                    comment[j] = "";
            }
            for (int i = 0; i < d_counter; i++)
                total_grade += student_grade[i];
        }
    }
    void print()const
    {
        if(d_counter != 0) {
            cout << "grades for descriptive questions:\n";
            for (int i = 0; i < d_counter; i++) {
                cout << i + 1 << "_ " << student_grade[i] << endl;
                if (comment[i] != "")
                    cout << comment[i] << endl;
            }
        }
        if(t_counter != 0) {
            cout << "result of test questions:\n";
            for (int i = 0; i < t_counter; i++)
                cout << i + 1 << "_ " << WR_answers[i] << endl;
        }
        cout<<"total grade:\n"<<total_grade<<endl;
    }
    int retExam_number()
    {
        return exam_number;
    }
    float retTotal()
    {
        return total_grade;
    }
    int ret_user()
    {
        return user;
    }
    bool ret_check()
    {
        return check;
    }
    ~correction()
    {
        delete[]d_grade;
        delete[]student_grade;
        delete[]d_answer;
        delete[]comment;
        delete[]t_grade;
        delete[]correctAnswer;
        delete[]t_answer;
        delete[]WR_answers;
    }
};

//-------------------------------------------------------------------------------------

struct protest
{
    string student_protest , professor_answer;
    int user , exam_num = 0;
    time_t now = time(0);
    char *dt;
    char *answer_dt;
    bool check = false;
    void registrationOfProtest(int n ,int u)
    {
        check = true;
        exam_num = n;
        user = u;
        cout<<"your pretset?\n";
        getline(cin>>ws , student_protest);
        dt = ctime(&now);
    }
    void showProtest()
    {
        int a;
        cout<<student_protest<<endl;
        cout<<"from student: "<<user<<" on exam number: "<<exam_num+1<<endl;
        cout<<"in date and time: "<<dt<<endl;
        while(true) {
            cout << "do you want to answer this protest?\n1_yes   2_no\n";
            cin >> a;
            if (a == 1) {
                getline(cin >> ws, professor_answer);
                answer_dt = ctime(&now);
                break;
            } else if (a == 2) {
                professor_answer = "";
                break;
            }
            else
                cout<<"invalid number!\n";
        }
    }
    void showAnswer()const
    {
        if(professor_answer != "")
        cout<<"professor answer to your protest: \n"<<professor_answer<<endl<<"in date and time: "<<answer_dt<<endl;
        else
            cout<<"no answers yet!\n";
    }
};

//-------------------------------------------------------------------------------------

class list
{
protected:
    vector<int>s_username;
    vector<int>s_password;
    int username , password;
public:
    void make_list()
    {
        int order = 1;
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
        int temp;
        int order = 1;
        while(order==1)
        {
            cout << "enter student username:" << endl;
            cin >> temp;
            auto x = find(s_username.begin() , s_username.end() , temp);
            if(x != s_username.end()) {
                s_username.erase(x);
                cout << "removed seccesfully!\n";
            }
            else
                cout << "not found" << endl;
       cout<<"press 1 if you want to continue or press 2 if you are done\n";
       cin>>order;
    }
    }
    void print_lists()const
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
        return s_username.size();
    }
};

//--------------------------------------------------------------------------------

void sorter(vector<int>user , vector<float>average , int size)
{
    int i_temp , s = size;
    float f_temp;
    for(int i=0 ; i<s-1 ; i++)
        for(int j=0 ; j<s-i-1 ; j++)
            if(average[j]>average[j+1])
            {
                f_temp = average[j];
                average[j] = average [j+1];
                average[j+1] = f_temp;
                i_temp = user[j];
                user[j] = user[j+1];
                user[j+1] = i_temp;
            }
}

//--------------------------------------------------------------------------------

class professor : public userpass
{
protected:
    int n , new_pass , number;
    string new_user;
    vector<exam>ex;
    vector<list>li;
    vector<correction>cor;
    vector<protest>pro;
    vector<int>user_temp;
    vector<float>average;
public:
    void order() {
        do {
            cout << "1_change usrename and password\n2_make an exam\n3_show exams\n4_Number of available exams\n";
            cout << "5_make a student list\n6_Number of available lists\n7_show lists\n8_add and remove student from a list\n";
            cout<<"9_add a student list to an exam\n10_correct exams\n11_show pretests\n12_sorting a list based on grades\n";
            cout<<"13_see a student grades\n14_sharing exam\n0_exit\n";
            cin >> n;
            switch (n) {
                case 1:
                    cout << "enter new username: ";
                    cin >> new_user;
                    cout << "enter new password (numbers only): ";
                    cin >> new_pass;
                    change_up(new_user, new_pass);
                    break;
                case 2: {
                    exam ob;
                    ob.questionType();
                    ex.push_back(ob);
                    break;
                }
                case 3:
                    cout<<"1_all exams   2_choose one exam\n";
                    cin>>number;
                    if(number == 1) {
                        if (ex.size() != 0)
                            for (int i = 0; i < ex.size(); i++) {
                                cout << "exam number " << i + 1 << " : "<<endl;
                                ex[i].print_questions();
                                cout << "-------------------------------------------" << endl;
                            }
                        else
                            cout<<"no exam was found\n";
                    }
                    else if(number == 2) {
                        cout << "exam number : ";
                        cin >> number;
                        if(number > 0 && number <= ex.size())
                            ex[number - 1].print_questions();
                        else
                            cout<<"No exam with this number was found!\n";
                    } else
                        cout<<"out of range!\n";
                    break;
                case 4:
                    cout << ex.size() << " exams\n";
                    break;
                case 5: {
                    list ob;
                    ob.make_list();
                    li.push_back(ob);
                    break;
                }
                case 6:
                    cout << li.size() << " student lists\n";
                    break;
                case 7:
                    cout<<"1_all lists   2_choose one list\n";
                    cin>>number;
                    if(number == 1) {
                        if (li.size() != 0)
                            for (int i = 0; i < li.size(); i++) {
                                cout << "list number " << i + 1 << " : "<<endl;
                                li[i].print_lists();
                                cout << "-------------------------------------------" << endl;
                            }
                        else
                            cout<<"no list was found!\n";
                    }
                    else if(number == 2) {
                        cout << "list number : ";
                        cin >> number;
                        if (number > 0 && number <= li.size())
                            li[number - 1].print_lists();
                        else
                            cout<<"No list with this number was found!\n";
                    }
                    else
                        cout<<"out of range!\n";
                    break;
                case 8:
                    int num;
                    cout << "list number : ";
                    cin >> number;
                    if(number > 0 && number <= li.size()) {
                        cout << "1_add or 2_remove student from list\n";
                        cin >> num;
                        if (num == 1)
                            li[number - 1].make_list();
                        else if(num == 2)
                            li[number - 1].remove_student();
                        else
                            cout<<"out of range!\n";
                    }
                    else
                        cout<<"No list with this number was found!\n";
                    break;
                case 9:
                    int l, e;
                    cout << "list number: ";
                    cin >> l;
                    cout << "to exam number: ";
                    cin >> e;
                    if(l > 0 && l <= li.size() && e > 0 && e <= ex.size())
                        ex[e - 1].setList_n(l - 1);
                    else
                        cout<<"no list or exam with this number was found!\n";
                    break;
                case 10: {
                    bool flag = false;
                    cout << "exam number: ";
                    cin >> number;
                    if(number > 0 , number <= ex.size()) {
                            for (int i = 0; i < cor.size(); i++)
                                if (cor[i].retExam_number() == (number - 1)) {
                                    cout << "student " << cor[i].ret_user() << endl;
                                    cor[i].descriptive_correction();
                                    cor[i].test_correction();
                                    cout << "total grade is: " << cor[i].retTotal() << endl;
                                    flag = true;
                                }
                            if (!flag)
                                cout << "No items were found to correct exam number " << number << endl;
                    }
                    else
                        cout << "No exam with this number was found!\n";
                    break;
                }
                case 11: {
                    bool flag = false;
                    cout << "protest's on exam number: ";
                    cin >> number;
                    if (number > 0 && number <= ex.size()) {
                        for (int i = 0; i < pro.size(); i++)
                            if ((number - 1) == pro[i].exam_num) {
                                pro[i].showProtest();
                                flag = true;
                            }
                        if(!flag)
                            cout<<"No protest have been registered on this exam\n";
                    } else
                        cout << "No exam with this number was found!\n";
                    break;
                }
                case 12:
                    cout << "list number: ";
                    cin >> number;
                    if(number > 0 && number <= li.size()) {
                        calculate(number);
                        sorter(user_temp, average, average.size());
                        cout << "student's grade's from higher to lower:\n";
                        for (int i = 0; i < average.size(); i++)
                            cout << user_temp[i] << "        " << average[i];
                    }
                    else
                        cout<<"No list with this number was found!\n";
                    break;
                case 13: {
                    int counter = 0 , u;
                    float avg = 0;
                    cout << "student username: ";
                    cin >> u;
                    for (int i = 0; i < cor.size(); i++) {
                        if (u == cor[i].ret_user()) {
                            cout << "exam " << cor[i].retExam_number() + 1 << " : " << cor[i].retTotal() << endl;
                            avg += cor[i].retTotal();
                            counter++;
                        }
                    }
                    if(counter == 0)
                        cout<<"No score has been recorded for a student with username "<<u<<endl;
                    else {
                        avg /= counter;
                        cout << "average: " << avg << endl;
                    }
                    break;
                }
                case 14:
                    int  w;
                    cout<<"exam number: ";
                    cin>>number;
                    if(number > 0 && number <= ex.size()) {
                        cout << "1_turn on   2_turn off   3_see all the shared exams\n";
                        cin >> w;
                        if (w == 1 || w == 2)
                            ex[number - 1].sharing(w);
                        else if (w == 3) {
                            for (int i = 0; i < ex.size(); i++)
                                if (ex[i].ret_share() == 0)
                                    cout << "exam number " << i + 1 << endl;
                        } else
                            cout << "out of range!\n";
                    }
                    else
                        cout<<"no exam with this number was found!\n";
            }
        } while (n != 0) ;
    }
    void calculate(int f)
    {
        user_temp.clear();
        average.clear();
        int temp, counter = 0;
        float avg = 0;
        for (int i = 0; i < li[f - 1].ret_n(); i++) {
            temp = li[f - 1].ret_username(i);
            user_temp.push_back(temp);
        }
        for (int j = 0; j < user_temp.size(); j++) {
            for (int i = 0; i < cor.size(); i++)
                if (user_temp[j] == cor[i].ret_user()) {
                    avg += cor[i].retTotal();
                    counter++;
                }
            if(counter != 0) {
                avg /= counter;
                average.push_back(avg);
            }
            else
                average.push_back(0);
            counter = 0;
            avg = 0;
        }
    }
    void student_answer(int a , int b , int c , int t)
    {
      correction ob;
      float grade;
      int correct;
      ob.set_data(a , b , c , t);
      ob.set_counter(ex[c].retD_counter() , ex[c].retT_counter());
      for(int i=0 ; i<(ex[c].retD_counter()) ; i++)
      {
          grade = ex[c].retD_grade(i);
          ob.set_Dgrade(i , grade);
      }
      for(int i=0 ; i<(ex[c].retT_counter()) ; i++)
      {
          grade = ex[c].retT_grade(i);
          correct = ex[c].ret_correct(i);
          ob.set_Tgrade(i , grade , correct);
      }
      cor.push_back(ob);
    }
    void student_protest(int n , int u)
    {
        bool found = false;
        if(pro.size() != 0) {
            for (int j = 0; j < pro.size(); j++)
                if (pro[j].user == u && pro[j].exam_num == n) {
                    cout << "you have already register your pretest!\n";
                    found = true;
                    break;
                }
        }
        if (!found) {
            protest ob;
            ob.registrationOfProtest(n, u);
            pro.push_back(ob);
        }
    }
};
//---------------------------------------------------------------------
class student : public professor
{
    int list_n;
    vector<int>saveExam;
public:
    bool s_check()
    {
        bool flag = false;
        int size;
        get_Suserpass();
        for(int i=0 ; i<li.size() ; i++) {
            size = li[i].ret_n();
            for (int j=0 ; j<size ; j++)
                if (s_username == li[i].ret_username(j) && s_password == li[i].ret_password(j)){
                        list_n = i;
                        flag = true;
                        break;
                    }
        }
        if(flag)
            cout << "welcome student " << s_username << endl;
        else if(!flag)
            cout<<"wrong information!\n";
        return flag;
    }
    void s_order()
    {
        int d , num;
        bool check;
        do {
            cout << "1_start exam\n2_see score\n3_protest on exam\n4_see protest's results\n5_history of exams\n";
            cout << "0_exit\n";
            cin >> d;
            switch(d)
            {
                case 1:
                    purging(1);
                    if (saveExam.size() == 0)
                        cout << "no exam found for you!\n";
                    else {
                        cout << saveExam.size() << " exams found for you\n";
                        cout << "which exam you want to answer? ";
                        cin >> num;
                        if (num > 0 && num <= saveExam.size()) {
                            if(isFirstTime(num))
                                cout<<"you have already answered this exam!\n";
                            else {
                                ex[saveExam[num - 1]].print_questions();
                                student_answer(s_username, s_password, saveExam[num - 1] , ex[saveExam[num-1]].ret_time());
                                cor[cor.size() - 1].get_answers();
                            }
                        }
                        else
                            cout<<"no exam with this number was found for you!\n";
                    }
                    break;
                case 2:
                    check = false;
                    purging(2);
                    if (saveExam.empty())
                        cout << "no exam was found for you!\n";
                    else {
                        cout << saveExam.size() << " exams registered on your name ,result of exam number? ";
                        cin >> num;
                        if (num > 0 && num <= saveExam.size()) {
                            for (int i = 0; i < cor.size(); i++)
                                if (s_username == cor[i].ret_user() && saveExam[num - 1] == cor[i].retExam_number()) {
                                    check = true;
                                    if (cor[i].ret_check())
                                        cor[i].print();
                                    else
                                        cout << "Not corrected yet!\n";
                                }
                            if (!check)
                                cout << "You have not answered this exam yet!\n";
                        }
                        else
                            cout << "no exam with this number was found for you!\n";
                    }
                    break;
                case 3:
                    purging(3);
                    if (saveExam.size() == 0)
                        cout << "no exam found for you to protest on!\n";
                    else {
                        cout <<saveExam.size()<<" exams registered on your name ,which exam you want to protest on? ";
                        cin >> num;
                        if(num > 0 && num <= saveExam.size())
                            student_protest(saveExam[num - 1], s_username);
                        else
                            cout << "no exam with this number was found for you!\n";
                    }
                    break;
                case 4:
                    check = false;
                    for (int j = 0; j < pro.size(); j++)
                        if (s_username == pro[j].user) {
                            pro[j].showAnswer();
                            check = true;
                        }
                    if(!check)
                        cout<<"no protest registered on your name!\n";
                    break;
                case 5:
                    check = false;
                    purging(5);
                    if(saveExam.size() == 0)
                        cout<<"no exam in your history!\n";
                    else
                    {
                        cout<<"1_all exams   2_choose a exam\n";
                        cin>>num;
                        if(num == 1) {
                            for (int i = 0; i < saveExam.size(); i++)
                                for (int j = 0; j < cor.size(); j++)
                                    if (saveExam[i] == cor[j].retExam_number() && s_username == cor[j].ret_user())
                                        if (cor[j].ret_check()) {
                                            cout << "exam number " << i + 1;
                                            ex[saveExam[i]].print_questions();
                                            cor[j].print();
                                            cout << "-------------------------------------------" << endl;
                                            check = true;
                                            break;
                                        }
                            if(!check)
                                cout<<"no exam in your history!\n";
                        }
                        else if(num == 2)
                        {
                            int h;
                            cout<<saveExam.size()<<" exams in your history, exam number: ";
                            cin>>h;
                            if(h > 0 && h<= saveExam.size()) {
                                for (int i = 0; i < cor.size(); i++)
                                    if (saveExam[h - 1] == cor[i].retExam_number() && s_username == cor[i].ret_user())
                                        if (cor[i].ret_check()) {
                                            ex[saveExam[h - 1]].print_questions();
                                            cor[i].print();
                                            check = true;
                                            break;
                                        }
                                if (!check)
                                    cout << "requsted exam not found!\n";
                            }
                            else
                                cout<<"out of range!\n";
                        }
                        else
                            cout<<"out of range!\n";
                    }
            }
        } while (d != 0);
    }
    bool isFirstTime(int n)
    {
        bool check = false;
        for(int i=0 ; i<cor.size() ; i++)
            if(cor[i].ret_user() == s_username && cor[i].retExam_number() == saveExam[n - 1]) {
                check = true;
                break;
            }
        return check;
    }
    void purging (int h)
    {
        saveExam.clear();
        if(h == 1) {
            for (int i = 0; i < ex.size(); i++)
                for (int j = 0; j < ex[i].retListSize(); j++)
                    if (ex[i].retList_n(j) == list_n)
                        if (ex[i].ret_share() == 0) {
                            saveExam.push_back(i);
                            break;
                        }
        }
        else if(h == 2 || h == 3) {
            for (int i = 0; i < ex.size(); i++)
                for (int j = 0; j < ex[i].retListSize(); j++)
                    if (ex[i].retList_n(j) == list_n)
                        if (ex[i].ret_share() != -1) {
                            saveExam.push_back(i);
                            break;
                        }
        }
        else if(h == 5) {
            for (int i = 0; i < ex.size(); i++)
                for (int j = 0; j < ex[i].retListSize(); j++)
                    if (ex[i].retList_n(j) == list_n)
                        if (ex[i].ret_share() == 1) {
                            saveExam.push_back(i);
                            break;
                    }
        }
    }
};

//---------------------------------------------------------------------------------

int main()
{
    student ob;
    int n;
    cout << "log in as : 1_professor  or  2_student\n";
    cin >> n;
    while(n == 1 || n == 2)
    {
        if (n == 1) {
            ob.get_Puserpass();
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
    return 0;
}