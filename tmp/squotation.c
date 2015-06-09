/** squotation.c: single quotation
 */
 
#include <stdio.h>
#include <sqlite3.h>

#define MAX_STRLEN	255	
int main(int argc, char *argv[])
{
	char str[MAX_STRLEN + 1] = {'A', 'B', 'C', '\'', '\'', 'D', '\'', '\'', '\"', 'E', '\"', 0};
	char str2[MAX_STRLEN + 1] = {0};
	char str3[] = "CREATE TABLE IF NOT EXISTS log(id INTEGER PRIMARY KEY, time INTEGER, level INTEGER, desc TEXT)";
	char str4[] = "Set network config{\"nic_mask\":0,\"enable\":1,\"id\":\"00181afb819f\",\"dhcp\":\"auto_ip\",\"name\":\"apcli0\",\"ip\":\"\",\"mask\":\"\",\"gateway\":\"\",\"dns\":\"\",\"wifi\":{\"ssid\":\"Xiaomi_0}}";

	sqlite3 *pdb;
	char *errmsg = NULL;

	if (SQLITE_OK != sqlite3_open("test.db", &pdb)) {
		printf("Fail to open\n");
		return -1;
	}

	if (SQLITE_OK != sqlite3_exec(pdb, str3, NULL, NULL, &errmsg)) {
		printf("%s\n", errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(pdb);
	}

	snprintf(str2, MAX_STRLEN, "INSERT INTO log (time, level, desc) values (2, 3, \'%s\');", str);

	printf("%s\n", str2);

	if (SQLITE_OK != sqlite3_exec(pdb, str2, NULL, NULL, &errmsg)) {
		printf("%s\n", errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(pdb);
	}

	snprintf(str2, MAX_STRLEN, "INSERT INTO log (time, level, desc) values (5, 6, '%s');", str4);

	printf("%s\n", str2);

	if (SQLITE_OK != sqlite3_exec(pdb, str2, NULL, NULL, &errmsg)) {
		printf("%s\n", errmsg);
		sqlite3_free(errmsg);
		sqlite3_close(pdb);
	}

	sqlite3_close(pdb);
	
	return 0;
}
