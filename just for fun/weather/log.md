#	As a memo

```python

#!/urs/bin/enc python3
# -*- coding: utf-8 -*-

from urllib import request
import re

re_seven_days = re.compile(r'\<h1\>([1-9].*)\</h1>\n.*\n.*\n.*\>(.*)\</p>\n.*\n\<span\>([0-9]*).*\>([0-9].*)\</i\>\n')

def get_weekly_weather():
	url = 'http://www.weather.com.cn/weather/101020100.shtml'
	req = request.Request(url)
	weekly_weather = request.urlopen(req).read().decode('utf-8')
	return weekly_weather

def get_weather(weekly_weather, index=2):
	seven_days = re_seven_days.findall(weekly_weather)
	if index < 1 and index > 7:
		index = 2
	for i in range(index):
		day = seven_days[i]
		print('\n', day[0], day[1], day[2], '~', day[3], '\n')
	return 1

get_weather(get_weekly_weather())



# V.01 with bs4
# from urllib import request
# from bs4 import BeautifulSoup

# url = 'http://www.weather.com.cn/weather/101020100.shtml'
# req = request.Request(url)
# weekly_weather = request.urlopen(req).read().decode('utf-8')

# soup = BeautifulSoup(weekly_weather, 'html.parser')
# seven_days = soup.find('ul', class_='t clearfix').get_text().split('\n')
# days = []
# for day in seven_days:
# 	if day != '':
# 		days.append(day)
# 	else:
# 		pass

# for i in range(2):
# 	print(days[i*4])
# 	print(days[i*4+1])
# 	print(days[i*4+2])
# 	print(days[i*4+3])
# 	print('\n')




# V.02 with re
# from urllib import request
# import re
# url = 'http://www.weather.com.cn/weather/101020100.shtml'
# req = request.Request(url)
# weekly_weather = request.urlopen(req).read().decode('utf-8')

# seven_days = re.findall(r'\<h1\>([1-9].*)\</h1>\n.*\n.*\n.*\>(.*)\</p>\n.*\n\<span\>([0-9]*).*\>([0-9].*)\</i\>\n', weekly_weather)
# # print(seven_days[0])
# print()
# for day in seven_days:
#  	print(day[0], day[1], day[2], day[3], '\n')



# else
# for i in range
# print(today)
# with open('data.md', 'w', encoding='utf-8') as f:
    # f.write(today)
# print(today)

```

