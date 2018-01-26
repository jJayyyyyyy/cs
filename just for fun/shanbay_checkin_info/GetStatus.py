#!/usr/bin/env python3
import re, sys, logging
import requests
from bs4 import BeautifulSoup

base_url = 'https://www.shanbay.com'
headers = {
	'Host': 'www.shanbay.com',
	'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
	'Accept-Encoding': 'gzip, deflate, br',
	'Accept-Language': 'zh-CN,zh;q=0.8',
	'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36'}

class Member(object):
	def __init__(self, id, name, status):
		self.id = id
		self.name = name
		self.status = status

	def get_id(self):
		return self.id

	def get_name(self):
		return self.name

	def get_status(self):
		return self.status

	def inform():
		if self.status:
			print("@%s " % self.name)

	def output(self):
		print("%s\t%s\t%s" % (self.id, self.name, self.status) )

def get_session(loginInfo):
	sess = requests.Session()	
	loginUrl = 'https://www.shanbay.com/api/v1/account/login/web/'
	sess.put( loginUrl, loginInfo, headers=headers )
	return sess

def get_group_page(sess, page=1):
	# if you are the group leader:
	# url = base_url + '/team/manage/?page=%d' % page
	
	# if you are a group member:
	url = base_url + '/team/members/?page=%d' % page

	resp = sess.get(url, headers=headers)
	# with open('page%s.html' % page, 'w') as f:
	# 	f.write(resp.text)
	return resp

def save(member_list, page=1):
	if page == 1:
		method = 'w'
	else:
		method = 'a'
	with open('Team.csv', method) as f:
		for m in member_list:
			f.write( m.get_id() + ', ' )
			f.write( m.get_name() + ', ' )
			f.write( '%d\n' % m.get_status() )

# if you are the group leader
def get_members(resp='', page=1):
	res = re.findall(r'.* data-id="(.*?)" data-name=(.*?)>\n', resp)
	book = {}
	for item in res:
		uid = item[0]
		name = item[1]
		book[uid] = name
	member_list = []
	soup = BeautifulSoup(resp.text, 'html.parser')
	soup_member = soup.find_all('tr', class_='member ')
	for m in soup_member:
		uid = m.get('data-id')
		status = m.find_all('td', class_='checked')[-1].find('span', class_='label label-success')
		name = book[uid]
		if status:
			status = 1
		else:
			status = 0
			print('@%s' % name, end=' ')
		member = Member(uid, name, status)
		member_list.append(member)
	save(member_list, page)

# if you are a group member
def get_members(resp='', page=1, is_member=True):
	soup = BeautifulSoup(resp, 'html.parser')
	soup_member = soup.find_all('tr', class_='member')
	for m in soup_member:
		status = m.find_all('td', class_='checked unchecked ')
		if status:
			name = m.find_all('a', class_='nickname')[0].text
			print("@%s" % name, end=' ')
	
def main():
	loginInfo = None
	if len(sys.argv) == 3:
		loginInfo = {
			'username': sys.argv[1],
			'password': sys.argv[2]}
	# loginInfo = {'username': 'zzzz', 'password': 'xxxx'}
	if loginInfo:
		try:
			sess = get_session(loginInfo)
			for i in [1, 2]:
				resp = get_group_page(sess, page=i)
				get_members(resp=resp.text, page=i, is_member=True)
			print('\n同学该打卡啦')
		except Exception as e:
			logging.exception(e)

if __name__ == '__main__':
	main()

