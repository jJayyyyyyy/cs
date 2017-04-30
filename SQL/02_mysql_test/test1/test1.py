import pymysql

try:
	conn = pymysql.connect(user='root', database='mydb')
	cursor = conn.cursor()
	cursor.execute('drop table if exists user')

	cursor.execute('create table user (id varchar(20) primary key, name varchar(20), score int )')
	
	cursor.execute('insert into user values (\'001\', \'hello\', 100)')
	cursor.execute('insert into user (id, name, score) values (%s, %s, %s)', ['002', 'Be', 13])
	
	cursor.execute('select * from user where id = %s', ('002',) )
	print( cursor.fetchall() )
	print(cursor.rowcount)
except Exception as e:
	print(e)
finally:
	cursor.close()
	conn.commit()
	conn.close()

