#pragma once
/*1650254 尤尧寅 计算机一班*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<Windows.h>
#include<fstream>
#include<io.h>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include <experimental/filesystem>
#include<strstream>
using namespace std;
enum ITEM_TYPE { TYPE_INT, TYPE_DOUBLE, TYPE_STRING, TYPE_CHARACTER, TYPE_NULL };
#define END -1
#define OK 0
//*************************
#define fname "test123.ini"
//坚坚！看这里！这里是文件名！
//*************************
int group_search(fstream &fp, const char *group_name);
int group_add(fstream &fp, const char *group_name);
int group_show(fstream &fp);
int group_del(fstream &fp, const char *group_name);
int group_save_temp(fstream &fp, char **save);
int item_search(fstream &fp, const char *group_name, const char *item_name);
int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
int item_del(fstream &fp, const char *group_name, const char *item_name);
int item_update(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
int item_get_value(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);