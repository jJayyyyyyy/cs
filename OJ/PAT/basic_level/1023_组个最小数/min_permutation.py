from __future__ import print_function

us_num = raw_input().split()
us_num = map(int, us_num)

first_num = 1

for i in range(1, 10):
	if us_num[i]:
		first_num = i
		us_num[i] -= 1
		break

print(first_num, end='')
for i in range(10):
	while us_num[i]:
		print(i, end='')
		us_num[i] -= 1
