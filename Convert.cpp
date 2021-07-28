﻿#include "Header\Convert.h"
#include "Header\File.h"
#include "Header\Node Process.h"

//*Thêm phần mở rộng (.csv) vào tên file hoặc cắt nó đi
//@param name Tên file @param option Loại hành động muốn thực thi (thêm/cắt)
//@return kết quả của chuỗi sau khi thêm/cắt
string Extension(string name, int option)
{
	//Nếu option là 1: thêm phần đuôi ".csv"
	if (option == 1) {
		return name + ".csv";
	}
	//Nếu option là 2: cắt phần đuôi
	else {
		size_t pos = 0;
		pos = name.find_last_of(".");
		return name.substr(0, pos);
	}
}

//*Tạo ra một đường dẫn từ đường dẫn thư mục chứa nó và tên file (ko có đuôi ".csv")  
//@param pre_folder một đường dẫn thư mục @param file_name một tên của file
//@return Đường dẫn hoàn chỉnh
string Make_Path(string pre_folder, string file_name)
{
	return  pre_folder + Extension(file_name, 1);
}

//*Cắt ra một tên (không có đuôi ".csv") từ một đường dẫn hoàn chỉnh
//@param path Một đường dẫn hoàn chỉnh
//@return Tên của file (không có extension)
string Path_ToName(string path)
{
	size_t pos = path.find_last_of("\\", path.length());
	return Extension(path.substr(pos + 1), 2);
}

//*Chuyển từ kiểu String sang kiểu Int
//@param s Chuỗi cần chuyển
//@return Giá trị int sau khi chuyển
int String_ToInt(string s)
{
	stringstream ss;
	int number;
	ss << s;
	ss >> number;
	ss.str("");
	ss.clear();
	return number;
}
//*Chuyển từ một tên năm sang kiểu int (lấy năm đầu tiên)(VD: 2002-2003 thì lấy 2002)
//@param year_name tên năm
//@return Dạng số int của năm đầu tiên trong tên năm
int Year_ToInt(string year_name)
{
	size_t pos = year_name.find_first_of("-", 0);
	string first_year = year_name.substr(0, pos);
	return String_ToInt(first_year);
}
//*Chuyển đổi từ ngày tháng sang chuỗi ngày tháng
//@param dmy Kiểu dữ liệu ngày tháng năm
//@return Chuỗi ngày tháng năm
string Date_toString(date dmy)
{
	return to_string(dmy.day)   + "/"
		  +to_string(dmy.month) + "/"
		  +to_string(dmy.year);
}

//*Chuyển đổi từ chuỗi ngày tháng sang kiểu ngày tháng
//@param dmy Chuỗi ngày tháng
//@return Kiểu dữ liệu ngày tháng
date String_ToDate(string dmy)
{
	date result;
	int length = dmy.length();
	int i = 1;
	string arr[3];
	while(i < 2)
	{
		int pos = dmy.find_first_of("/", 0);
		string temp = dmy.substr(0, pos);
		arr[i++]= temp;
		dmy = dmy.substr((uint64_t)pos + 1, length);
	}
	result.day=String_ToInt(arr[0]);
	result.month=String_ToInt(arr[1]);
	result.year=String_ToInt(arr[2]);
	return result;
}

//*Chuyển đổi từ chuỗi thông tin học sinh sang kiểu học sinh
//@param info Chuỗi thông tin
//@param arr[8] mảng lưu thông tin nếu cần dùng kiểu mảng
//@return Thông tin học sinh dạng struct
Student String_ToStudent(string info, string arr[8])
{
	Student s;
	int length = info.length();
	int k = 0;
	string temp = info;
	string a[8];
	while (k < 7)
	{
		int pos = info.find_first_of(",", 0);
		string temp2 = info.substr(0, pos);
		info = info.substr((uint64_t)pos + 1, length);
		a[k++] = temp2;
	}
	s.number = String_ToInt(a[0]);
	s.id = String_ToInt(a[1]);
	s.name = a[2];
	s.gender = a[3];
	s.faculty = a[4];
	s.birthdate = a[5];
	s.socialID = stoi(a[6]);
	s.user.username = a[1];
	int pos = temp.find_last_of(",", temp.size());
	s.user.password = temp.substr((uint64_t)pos + 1, temp.size() - pos);
	return s;
}
//*Chuyển từ kiểu học sinh sang chuỗi học sinh
//@param info kiểu học sinh
//@return chuỗi học sinh
string Student_ToString(Student s)
{
	string result;
	result += (to_string(s.number) + "," + to_string(s.id) + "," + s.name + "," + s.gender + "," + s.faculty + ",");
	result += (s.birthdate + "," + to_string(s.socialID) + "," + s.user.username + "," + s.user.password);
	return result;
}
//*Chuyển từ kiểu chuỗi sang kiểu môn học
//@param info Dữ liệu môn học dạng chuỗi
//@param arr[7] Mảng lưu dữ liệu khi tách ra nếu cần dùng
//@return Kiểu dữ liệu môn học
Course String_ToCourse(string info, string arr[7])
{
	Course c;
	int length = info.size();
	int i = 0;
	while (i <= 6)
    {
        int pos = info.find_first_of(",", 0);
        string temp = info.substr(0, pos);
		if(i<6)
		{
			info = info.substr((uint64_t)pos + 1, length);
			arr[i++] = temp;
		}
		else{
			arr[i++] = info;
		}
    }
	c.id=arr[0];
	c.name=arr[1];
	c.teacher=arr[2];
	c.cre=String_ToInt(arr[3]);
	c.capacity=String_ToInt(arr[4]);
	c.day=arr[5];
	c.session=arr[6];
	return c;
}
//*Chuyển từ môn học sang kiểu chuỗi
//@param Kiểu môn học
//@return Chuỗi môn học
string Course_ToString(Course c)
{
	return c.id + "," + c.name + "," + c.teacher + "," + 
		   to_string(c.cre) + "," + to_string(c.capacity) + "," + c.day + "," + 
		   c.session;
}
//*Lấy ra tên môn học từ Chuỗi môn học
//@param course_string Chuỗi môn học
//@return Tên môn học
string CourseString_To_CourseName(string course_string)
{
	int pos = course_string.find_first_of(",",0);
	course_string.replace(pos,1,"/");
	int pos2 = course_string.find_first_of(",",0);
	course_string.replace(pos2,1,"_");
	int pos3 = course_string.find_first_of(",",0);
	return course_string.substr((double)pos+1,(double)pos3-pos-1);
}
//*Thay đổi 1 ký tự trong chuỗi thành ký tự khác
//@param &s chuỗi cần thay thế ký tự
//@param target Chuỗi được thay 
//@param change Chuỗi cần thay 
void String_Replace(string &s, string target, string change)
{
	string temp = s;
	int pos = 0;
	while(pos != string::npos)
	{
		pos = temp.find_first_of(target, 0);
		if(pos == string::npos) break;
		temp.replace(pos, 1, change);
	}
	s = temp;
}

//*Lưu các string từ file sang danh sách liên kết
//@param path Đường dẫn chứa file
//@return Danh sách liên kết chứa các chuỗi
strings File_to_LinkList(string path)
{
	strings l = Init_List();
	ifstream f;
	f.open(path);
	while (!f.eof())
	{
		string f1;
		getline(f, f1);
		str* p = Create_Node(f1);
		Add_Last(l, p);
	}
	f.close();
	return l;
}

//*Ghi dữ liệu từ file sang mảng string
//@param path Đường dẫn file
//@return Vector chứa string
vector<string> File_toStringArray(string path)
{
	vector<string> s;
	int n = Count_line(path);
	fstream file;
	file.open(path);
	int i = 0;
	while (!file.eof())
	{
		string s1;
		getline(file, s1);
		s.push_back(s1);
	}
	file.close();
	return s;
}
