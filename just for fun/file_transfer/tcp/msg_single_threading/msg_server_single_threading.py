#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket, threading, time
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1', 8888))
s.listen(5)
print('Waiting for connection...')

sock, addr = s.accept()
sock.send(b'Welcome!')
while True:
    data = sock.recv(1024)
    print(data.decode('utf-8'))
    # time.sleep(0.5)
    if not data or data.decode('utf-8') == 'exit':
        break
    sock.send(b'Hello, ' + data)
s.close()
print('Connection from %s:%s closed.' % addr)
