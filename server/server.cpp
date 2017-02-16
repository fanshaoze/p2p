// server.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#include "stdafx.h"


int main(int argc, char **argv)
{
	const char *s;
	int i;
	MYSQL mysql_conn; /* Connection handle */
	MYSQL_RES *mysql_result; /* Result handle */
	mysql_result = NULL;
	MYSQL_ROW mysql_row; /* Row data */
	int f1, f2, num_row, num_col;

	if (mysql_init(&mysql_conn) != NULL)
	{
		if (mysql_real_connect( 
			&mysql_conn, "localhost", "root", "root", "company", MYSQL_PORT, NULL, 0) != NULL)
		{
			if (mysql_query(&mysql_conn, "select * from employee") == 0)
			{
				mysql_result = mysql_store_result(&mysql_conn);
				num_row = mysql_num_rows(mysql_result);
				num_col = mysql_num_fields(mysql_result);

				for (f1 = 0; f1 < num_row; f1++)
				{
					mysql_row = mysql_fetch_row(mysql_result);

					for (f2 = 0; f2 < num_col; f2++)
						printf(
							"[Row %d, Col %d] ==> [%s]\n",
							f1 + 1, f2 + 1, mysql_row[f2]);
				}
			}
			else printf("Query fails\n");
		}
		else
		{
			i = mysql_errno(&mysql_conn);
			s = mysql_error(&mysql_conn);
			printf("Connection fails(ERROR %d): %s\n", i, s);
		}
	}
	else printf("Initialization fails\n");

	mysql_free_result(mysql_result);
	mysql_close(&mysql_conn);
	return 0;
}
