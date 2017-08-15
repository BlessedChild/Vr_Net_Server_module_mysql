# Vr_Net_Server_module_mysql

    (Environment: MacOS 10.12.6)
    Run testmysql after completing the following operations:

    1.install mysql
    
    2.update password
    "mysql -u root -p xuge0754"

    3.create database test
    "myqsl -u root -p"
    "xuge0754"
    "create database test;"
    "exit;"
    
    4.cd to testmysql.c directory
    "gcc -c testmysql.c -I /usr/local/mysql/include/" --the mysql cflag path
    "gcc testmysql.o -o testmysql -L /usr/local/mysql/lib -lmysqlclient" --the mysql lib and c api path
    "./testmysql" --run testmysql
