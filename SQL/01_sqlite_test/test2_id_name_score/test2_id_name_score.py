# -*- coding: utf-8 -*-

import os, sqlite3

db_file = os.path.join(os.path.dirname(__file__), 'test.db')
if os.path.isfile(db_file):
	os.remove(db_file)

conn = sqlite3.connect(db_file)
cursor = conn.cursor()
cursor.execute( 'create table user (id varchar(20) primary key, name varchar(20), score int)' )
cursor.execute( "insert into user values ('A-001', 'Adam', 95)" )
cursor.execute( "insert into user values ('A-002', 'Bart', 62)" )
cursor.execute( "insert into user values ('A-003', 'Lisa', 78)" )

cursor.close()
conn.commit()
conn.close()

def get_score_in(low, high):
	name_tuple_list = []
	try:
		conn = sqlite3.connect(db_file)
		cursor = conn.cursor()
		cursor.execute( 'select name from user where score between ? and ? order by score asc', (low, high) )
		name_tuple_list = cursor.fetchall()
	except Exception as e:
		print(e)
	finally:
		cursor.close()
		conn.commit()
		conn.close()
	name_list = []
	for name_tuple in name_tuple_list:
		# print(name_tuple[0])
		name_list.append(name_tuple[0])
	return name_list


assert get_score_in(80, 95) == ['Adam'], get_score_in(80, 95)
assert get_score_in(60, 80) == ['Bart', 'Lisa'], get_score_in(60, 80)
assert get_score_in(60, 100) == ['Bart', 'Lisa', 'Adam'], get_score_in(60, 100)

print('Pass')
