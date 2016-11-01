#!/urs/bin/enc python3
# -*- coding: utf-8 -*-
from urllib import request
from bs4 import BeautifulSoup

url_sh = 'http://www.weather.com.cn/weather/101020100.shtml'

def get_weekly_weather(url=url_sh):
	req = request.Request(url)
	weekly_weather = request.urlopen(req).read().decode('utf-8')
	return weekly_weather

def get_weather(weekly_weather, index=2):
	soup = BeautifulSoup(weekly_weather, 'html.parser')
	seven_days = soup.find('ul', class_='t clearfix').get_text().split('\n')
	days = []
	for day in seven_days:
		if day != '':
			days.append(day)
	for i in range(index):
		r = map(print, days[i*4:i*4+4])
		list(r)
		print('\n')
	return 1

get_weather(get_weekly_weather())
