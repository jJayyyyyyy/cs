#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from urllib import request, parse
import re
# import sys

word = parse.quote(input())
# word = parse.quote(sys.argv[1])
url = 'http://dict.youdao.com/fsearch?q=' + word

resp = request.urlopen(url).read().decode('utf-8')
data = re.findall(r'<content><\!\[CDATA\[(.*)\]\]>', resp)

for i in data:
	print('\n' + i)
