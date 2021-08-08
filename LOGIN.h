#include"MainSource.h"

bool compare(string s1, string s2);

string delete_last(string s);

// check day
bool check_leap_year(int year);
int day_of_month(int month, int year);
bool check_dmy(date dmy);
void enter_dmy(date& dmy);
// check option
int Valid_Data(int limit);
// password proccess
int enterpass();
void showpass(string& pass);
void hidepass(string& pass, string name);
bool enterpass_proc(int option, string& psw, string name);
bool enter_acc(user& info);
// count line in file csv
int count_acc(string name);
// create account
string account(user info);
// check account

//Login as ad
string* split_acc_ad(string s);
bool check_acc_ad(user info);
bool login_as_admin(user& info, date& dmy);
//Login as stu
bool check_acc_student(user info);
bool login_as_student(user& info, date& dmy);

