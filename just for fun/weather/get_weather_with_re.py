#!/urs/bin/enc python3
# -*- coding: utf-8 -*-
from urllib import request
import re

url_sh = 'http://www.weather.com.cn/weather/101020100.shtml'
re_seven_days = re.compile(r'<h1>([1-7].*)</h1>\n.*\n.*\n.*class="wea">(.*)</p>\n.*\n<span>([0-9]*).*>([0-9].*)</i>\n')

# re_tonight = re.compile(r'<h1>([1|2].*)</h1>\n.*\n.*\n.*class="wea">(.*)</p>\n.*\n.*<i>([0-9].*)</i>\n')

def get_weekly_weather(url=url_sh):
	req = request.Request(url)
	weekly_weather = request.urlopen(req).read().decode('utf-8')
	return weekly_weather

def get_weather(weekly_weather, index=2):
	seven_days = re_seven_days.findall(weekly_weather)
	# tonight = re_tonight.findall(weekly_weather)
	# if tonight:
	# 	print('\n', tonight[0][0], tonight[0][1], tonight[0][2], '\n')
	if index < 1 and index > 7:
		index = 2
	for i in range(index):
		day = seven_days[i]
		print('\n', day[0], day[1], day[2], '~', day[3], '\n')
	return 1

get_weather(get_weekly_weather())
