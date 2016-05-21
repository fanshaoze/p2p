#pragma once
#include <iostream>
#include <WinSock2.h>
#include <windows.h>
#include <string.h>
#include <malloc.h>
#include <mysql.h>
using namespace std;
void search(MYSQL *mysql_conn_d, MYSQL_RES *mysql_result, string title, char * ip,char * port);