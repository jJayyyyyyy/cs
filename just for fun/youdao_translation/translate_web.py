#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from urllib import request, parse
import sys, re

word = parse.quote(sys.argv[1])
url = 'http://dict.youdao.com/fsearch?q=' + word

req = request.Request(url)
resp = request.urlopen(req).read().decode('utf-8')

data = re.findall(r'<content><\!\[CDATA\[(.*)\]\]>', resp)

for i in data:
	print('\n' + i)
