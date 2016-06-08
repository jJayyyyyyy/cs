#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from html.parser import HTMLParser
class MyHTMLParser(HTMLParser):
    def __init__(self):
        HTMLParser.__init__(self)
        self.flag = 0

    def handle_data(self, data):
        for i in range(1):
            if self.flag==1:
                print(data)

    def handle_starttag(self, tag, attrs):
        if(tag=='span'):
            for name, value in attrs:
                if name == 'class' and value =='b':
                    self.flag=1

    def handle_endtag(self, tag):
        if tag=='span':
            self.flag=0

with open ('weather.html', 'r') as f:
    data = f.read()
parser = MyHTMLParser()
parser.feed(data)
