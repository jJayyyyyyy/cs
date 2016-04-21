#!/usr/bin/python3
# -*- coding: utf-8 -*-
import socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_host = '192.168.1.104'
port = 8000

while True:
    data = input('Input data here: ')
    s.sendto(data.encode('utf-8'), (server_host, port))
    if not data:
        print('Quit!\n')
        break
    print("From server: %s\n" % s.recv(1024).decode('utf-8'))

s.close()
