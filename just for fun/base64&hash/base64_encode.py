import base64
s = 'hello world'
p = base64.urlsafe_b64encode(s.encode('utf-8'))
print(p)
s = base64.urlsafe_b64decode(p).decode('utf-8')
print(s)
