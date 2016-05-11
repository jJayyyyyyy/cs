#!/usr/bin/python3
# -*- coding: utf-8 -*-
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_host = '192.168.1.104'
port = 8000
s.bind((server_host, port))
print('\nserver_host: %s\tport: %d\n' % (server_host, port))

while True:
    data, addr = s.recvfrom(1024)
    if not data:
        print('Client offline!\n')
        break
    print('Received from %s:%s' % addr)
    print('data: %s\n' % data.decode('utf-8'))
    s.sendto(b'Hello '+ addr[0].encode('utf-8'), addr)

s.close()
