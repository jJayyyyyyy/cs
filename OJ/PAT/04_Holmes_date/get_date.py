from __future__ import print_function

s1 = raw_input()
s2 = raw_input()
s3 = raw_input()
s4 = raw_input()

len1, len2, len3, len4 = len(s1), len(s2), len(s3), len(s4)
cnt_i= 0, 0
answer = [-1, -1, -1]

if len1>len2:
	len1 = len2

for i in range(len1):
	if s1[i]>='A' and s1[i]<='G':
		if s2[i]>='A' and s2[i]<='G':
			if s1[i]==s2[i]:
				answer[0] = s1[i]
				cnt_i = i+1
				break
	if answer[0]!=-1:
		break

for i in range(cnt_i, len1):
	if (s1[i]>='A' and s1[i]<='N') or (s1[i]>='0' and s1[i]<='9'):
		if (s2[i]>='A' and s2[i]<='N') or (s2[i]>='0' and s2[i]<='9'):
			if s1[i]==s2[i]:
				answer[1] = s1[i]
				break
	if answer[1]!=-1:
		break

if len3>len4:
	len3=len4

for i in range(len3):
	if (s3[i]>='A' and s3[i]<='Z') or (s3[i]>='a' and s3[i]<='z'):
		if s3[i]==s4[i]:
			answer[2] = i
			break

day_list = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
day = day_list[ord(answer[0])-65]

hour = ord(answer[1])-65
if hour<0:
	hour = '0' + answer[1]
else:
	hour = str(hour+10)

if answer[2]<10:
	minute = '0' + str(answer[2])
else:
	minute = str(answer[2])

print(day, hour+':'+minute)







'''

aaFqweJasdK FasdSasdJasdWasdK 123 123

3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm

3485djDkxhAhhGE 2984akDfkkkkggAdsb s&hgsfdk d&Hyscvnm

3485djDkxh4hhGE 2984akDfkkkkgg4dsb s&hgsfdk d&Hyscvnm

3485djDkxh0hhGE 2984akDfkkkkgg0dsb s&hgsfdk d&Hyscvnm





# us_str = ['0']*4
# us_str_len = [0]*4
# cnt_i, cnt_j = 0, 0
# answer = [-1]*3

# for i in range(4):
# 	us_str[i] = raw_input()
# 	us_str_len[i] = len(us_str[i])

# for i range(us_str_len[0]):
# 	if us_str[0][i]>='A' and us_str[0][i]<='Z':
# 		for j in range(us_str_len[1]):
# 			if us_str[1][j]>='A' and us_str[1][j]<='Z':
# 				if us_str[0][i]



'''
