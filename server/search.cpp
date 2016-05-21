#include "search.h"

void search(MYSQL *mysql_conn_d, MYSQL_RES *mysql_result, string title, char * ip, char * port)
{

	MYSQL_ROW mysql_row; /* Row data */
	int f1, f2, num_row, num_col, flag;
	string command = "select ip,port from filelist where filename = '" + title + "'";
	char *command_char;
	command_char = const_cast<char*>(command.c_str());
	cout << command_char << endl;
	//command_char = "select * from employee";
	if (mysql_query(mysql_conn_d, command_char) == 0)
	{
		mysql_result = mysql_store_result(mysql_conn_d);
		num_row = mysql_num_rows(mysql_result);
		num_col = mysql_num_fields(mysql_result);

		mysql_row = mysql_fetch_row(mysql_result);
		strcpy(ip, mysql_row[0]);
		strcpy(port, mysql_row[1]);
		/*
		for (f1 = 0; f1 < num_row; f1++)
		{
			mysql_row = mysql_fetch_row(mysql_result);
			for (f2 = 0; f2 < num_col; f2++)
				printf("[Row %d, Col %d] ==> [%s]\n", f1 + 1, f2 + 1, mysql_row[f2]);
		}
		*/
		mysql_free_result(mysql_result);
	}
	else
	{
		printf("Query fails\n");
		ip = "#";
		port = "#";
		mysql_free_result(mysql_result);
		mysql_close(mysql_conn_d);
	}
}