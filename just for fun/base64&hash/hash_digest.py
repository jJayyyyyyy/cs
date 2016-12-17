import hashlib
#	md5
s = 'hello world'
md5 = hashlib.md5()
md5.update(s.encode('utf-8'))
p = md5.hexdigest()
print(p)

#	sha1
s = 'hello world'
sha1 = hashlib.sha1()
sha1.update(s.encode('utf-8'))
p = sha1.hexdigest()
print(p)
