#!/usr/bin/env python3

import requests, time, random, sys

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.2; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/57.0.2987.110 Safari/537.36'}

def getSession(loginInfo):
	loginUrl = 'https://www.shanbay.com/api/v1/account/login/web/'
	s = requests.Session()
	s.put( loginUrl, loginInfo, headers=headers )
	return s

def doReading(s):
	newsUrl = 'https://www.shanbay.com/api/v1/read/article/news/?ipp=15&page=1'
	reading = s.get(newsUrl, headers=headers).json()
	articles = reading['data']['articles'];

	for i in range(3):
		article = articles[i]
		if article['finished'] is False:
			news_id = str(article['id'])
			minSec = str( article["min_used_seconds"] + random.randint(20, 40) )
			print(article["min_used_seconds"], minSec)
			formData = {"operation": "finish",
						"used_time": minSec}
			articleUrl = "https://www.shanbay.com/api/v1/read/article/user/%s/" % news_id
			resp = s.put( articleUrl, formData, headers=headers).json()
			print( 'article 【 %i 】: %s' % (i, resp['msg']) )
			print( 'time used: %d' % int(minSec) )
			time.sleep( int(minSec) + 10 )

	time.sleep(10)

def doCheckIn(s):
	checkinUrl = 'http://www.shanbay.com/api/v1/checkin/?for_web=true'
	resp = s.post( checkinUrl, headers=headers ).json()
	print( 'checkin msg: %s' % resp['data'])

def main():
	if len( sys.argv ) is 2:
		loginInfo = {
			'username': sys.argv[1],
			'password': sys.argv[2]
		}
		s = getSession(loginInfo)
		doReading(s)
		doCheckIn(s)
	else:
		print('\nPlease input username and password\n')

main()