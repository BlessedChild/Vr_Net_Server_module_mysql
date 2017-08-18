#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

/* gcc -c testmysql.c -I /usr/local/mysql/include/ */
/* gcc testmysql.o -o testmysql -L /usr/local/mysql/lib/ -lmysqlclient */
 
MYSQL mysql;
char buf[1024*2]={0};

int main(int argc, const char* argv[])
{
    mysql_init(&mysql);

    if(!mysql_real_connect(&mysql, "localhost", "root", "a", "test", 0, NULL, 0)){
        printf("connecting to mysql error:%d from %s\n", mysql_errno(&mysql), mysql_error(&mysql));
        return -1;
    }else{
        printf("connected mysql successful!\n");

        //sprintf(buf,"insert into user values(null,'xuge888','12345678')");
        sprintf(buf,"select * from user where binary name='xuge666' and password='12345678'");
        //ASC2UTF8(buf,buf,sizeof(buf));//转编码，将ASC转为UTF8  以便数据库可以识别sql语句
        int iSuccess = mysql_query(&mysql,buf);//执行mysql语句
        if(iSuccess != 0)
        {
            printf("mysql_query:%s\r\n",mysql_error(&mysql));
        }
        else
        {
            //printf("insert data to mysql successful!\n");
            printf("client sing in successful!\n");
        }
    }

    mysql_close(&mysql);
    return 0;
}