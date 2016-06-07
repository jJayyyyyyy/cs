#!/usr/bin/env python3
# -*- coding: utf-8 -*-
with open('test.txt', 'w') as f:
    f.write('abcd')

with open('test.txt', 'rb') as f:
    while True:
        data = f.read(1)
        print(data.decode('utf-8'))
        if data.decode('utf-8') == '':
            break
print('done')
