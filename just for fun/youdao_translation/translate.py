#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from urllib import request, parse
import json

keyfrom = 'keyfrom'	#use <keyfrom> of your api-key
key = 'key'			#use <key> of your api-key
word = parse.quote(input())
url = 'http://fanyi.youdao.com/openapi.do?keyfrom=%s&key=%s&type=data&doctype=json&version=1.1&q=%s' % (keyfrom, key, word)

req = request.Request(url)
req.add_header('User-Agent', 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.87 Safari/537.36')

with request.urlopen(req) as f:
    # print('Status:', f.status, f.reason + '\n')
    print('')
    if(200 == f.status):
        data = f.read()
        json_data = json.loads(data.decode('utf-8'))
        try:
            print(json_data['basic']['explains'])
        except:
            print(json_data['translation'])
    else:
        print('Status Error!\n')

# with open('test.json', 'w') as test:
#     test.write(data.decode('utf-8'))
#     test.close()
