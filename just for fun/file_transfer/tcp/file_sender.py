#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket, sys
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 8888))
print(s.recv(1024).decode('utf-8'))

s.send(sys.argv[1].encode('utf-8'))
with open(sys.argv[1], 'rb') as f:
    data = f.read()
s.send(data)

data=input('\nDone! Press any key to continue...')
s.send(b'exit')
s.close()
