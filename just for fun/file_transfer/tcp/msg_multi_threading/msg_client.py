#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 8888))
print(s.recv(1024).decode('utf-8'))

while True:
    data = input()
    if data == 'exit':
        break
    else:
        s.send(data.encode('utf-8'))
        print(s.recv(1024).decode('utf-8'))
s.send(b'exit')
s.close()

# for data in [b'Michael', b'Tracy', b'Sarah']:


# buf=1
# with open('test.txt', 'r') as f:
#     buf=f.read()
# print(buf)
# with open('test2.txt', 'w') as f:
#     f.write(buf)
#     f.write('world\n\n\n\tthis is houston')
