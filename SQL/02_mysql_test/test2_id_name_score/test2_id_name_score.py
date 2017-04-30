#/usr/bin/env python3
# -*- coding: utf-8 -*-

import pymysql

conn = pymysql.connect(user='root', database='mydb')
cursor = conn.cursor()
cursor.execute( 'drop table if exists user' )
cursor.execute( 'create table user (id varchar(20) primary key, name varchar(20), score int )' )
cursor.execute( "insert into user values ('A-001', 'Adam', 95)" )
cursor.execute( "insert into user values ('A-002', 'Bart', 62)" )
cursor.execute( "insert into user values ('A-003', 'Lisa', 78)" )
cursor.close()
conn.commit()
conn.close()

def get_score_in(low, high):
	res = []
	try:
		conn = pymysql.connect(user='root', database='mydb')
		cursor = conn.cursor()
		cursor.execute( "select name from user where score between %s and %s order by score asc", (low, high) )
		res = cursor.fetchall()
	except Exception as e:
		print(e)
	finally:
		cursor.close()
		conn.close()
	name_list = []
	for name in res:
		name_list.append(name[0])
	return name_list

assert get_score_in(80, 95) == ['Adam'], get_score_in(80, 95)
assert get_score_in(60, 80) == ['Bart', 'Lisa'], get_score_in(60, 80)
assert get_score_in(60, 100) == ['Bart', 'Lisa', 'Adam'], get_score_in(60, 100)

print('Pass')
