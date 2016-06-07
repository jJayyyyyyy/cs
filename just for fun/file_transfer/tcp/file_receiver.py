#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import socket, threading
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('127.0.0.1', 8888))
s.listen(5)
print('Waiting for connection...')

def tcplink(sock, addr):
    print('Accept new connection from %s:%s...' % addr)
    sock.send(b'Connected!')
    while True:
        filename = 't_'+sock.recv(1024).decode('utf-8')
        data = sock.recv(1024)
        if not data or data.decode('utf-8') == 'exit':
            break
        with open(filename, 'wb') as f:
            f.write(data)
    sock.close()
    print('File received. Connection from %s:%s closed.' % addr)

while True:
    sock, addr = s.accept()
    t = threading.Thread(target=tcplink, args=(sock, addr))
    t.start()
