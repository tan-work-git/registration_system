#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <direct.h>
#include <filesystem>
#include <sstream>
using namespace std;

//
struct date {
    int day, month, year;
};
struct user {
    string username;
    string password;
};
//
struct path {
	string info;
	path* next;
};
struct paths {
	path* head;
	path* tail;
};

