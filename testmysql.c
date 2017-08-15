#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>


/* gcc -c testmysql.c -I /usr/local/mysql/include/ */
/* gcc testmysql.o -o testmysql -L /usr/local/mysql/lib/ -lmysqlclient */
 
MYSQL mysql;

int main(int argc, const char* argv[])
{
    mysql_init(&mysql);

    if(!mysql_real_connect(&mysql, "localhost", "root", "xuge0754", "test", 0, NULL, 0)){
        printf("connecting to mysql error:%d from %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        return -1;
    }else{
        printf("connected mysql successful!\n");
    }

    mysql_close(&mysql);
    return 0;
}
