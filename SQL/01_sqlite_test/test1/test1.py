import sqlite3

conn = sqlite3.connect('test.db')
cursor = conn.cursor()

try:
	cursor.execute('create table user (id varchar(20) primary key, name varchar(20) )')
	cursor.execute('insert into user (id, name) values (\'001\', \'Ali\')')
	cursor.execute('insert into user (id, name) values (\'002\', \'BBB\')')
	cursor.execute('insert into user (id, name) values (\'003\', \'ccc\')')

	print(cursor.rowcount)

	cursor.execute( 'select * from user where id between ? and ?', ('001', '003') )
	print(cursor.fetchall())

	cursor.execute('drop table if exists user')
except Exception as e:
	print(e)

finally:
	cursor.close()
	conn.commit()
	conn.close()