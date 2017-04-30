*   Python 标准数据库接口为 Python DB-API，由于Python的DB-API定义都是通用的，所以，操作MySQL的数据库代码和SQLite类似。

*   表是数据库中存放关系数据的集合，一个数据库里面通常都包含多个表，比如学生的表，班级的表，学校的表，等等。表和表之间通过外键关联。

*   要操作关系数据库，首先需要连接到数据库，一个数据库连接称为Connection；

*   连接到数据库后，需要打开游标，称之为Cursor，通过Cursor执行SQL语句，然后，获得执行结果。

*   Python定义了一套操作数据库的API接口，任何数据库要连接到Python，只需要提供符合Python标准的数据库驱动即可。

*   sqlite3过程

    *   connect 到数据库
    *   建立cursor
    *   create table建立表
    *   insert into插入数据，注意占位符是`?`
    *   select * from user where查找数据
    *   cursor.close()
    *   conn.commit()
    *   conn.close()
    
*   mysql过程（基于c9）shell

    *   `$ mysql-ctl start`     #终端运行mysql
    *   `$ mysql -u root`       #进入数据库
    *   `> show databases;`
    *   `> drop database if exists mydb;`
    *   `> create database if not exists mydb;`
    *   `> connect mydb;`
    *   `> drop table if exists user;`
    *   `> create table user (id varchar(20) primary key, name varchar(20), score int);`
    *   `> insert into user values ('001', 'Alice', 99);`
    *   `> describe user;`
    *   `> select * from user;`
    *   `> drop table if exists user;`
    *   `> ^D`
    *   `$ mysql-ctl stop`      #终止mysql

*   mysql过程（基于c9）python3

    *   py3需要安装驱动pymysql
    *   运行mysql
    *   `pymysql.connect(user='root', database='mydb')`  #连接到数据库
    *   建立cursor
    *   同sqlite，注意占位符是`%s`
    *   `$ mysql-ctl stop`      #终止mysql
