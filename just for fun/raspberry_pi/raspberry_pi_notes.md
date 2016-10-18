1.	[硬件 GPIO 串行连接](http://shumeipai.nxez.com/2014/05/04/under-windows-serial-connection-control-raspberry-pi.html)

	右3接GND
	右4接Rx
	右5接Tx

2.	将刻好的SD卡插入树莓派，插电即开机。

	帐号 pi
	密码 raspberry

	[关机](http://shumeipai.nxez.com/2013/08/25/raspberry-pi-how-to-safely-shutdown-restart.html)

	```bash
	$ sudo shutdown -h now #或
	$ sudo halt
	$ sudo poweroff
	```

	关机之后再拔电源。

	重启

	```
	$ sudo reboot 。
	```

3.	连接wifi

	[link1](http://my.oschina.net/u/2306127/blog/392442?fromerr=Jv4CiDZE)

	[link2](http://tieba.baidu.com/p/2960687787)

4.	ssh

	```
	$ nano /etc/ssh/ssh_config
	```

	把PermitRootLogin 的 yes 改成 no，下次就可以用ssh登录了

	```
	$ ssh pi@192.168.1.105
	```

	再输入密码即可登录

	登出

	```
	$ logout
	```

	移除`ssh host`

	```
	$ ssh-keygen -R 192.168.1.105
	```


5. 通过win7共享wifi联网

	不管有没有入域，无线共享给有线以后，有线会变成192.168.137.1。设置树莓派有线网卡`eth0`

	```
	$ sudo nano /etc/network/interfaces


	auto eth

	iface eth0 inet static
	address 192.168.137.99
	netmask 255.255.255.0
	gateway 192.168.137.1
	```

	即可通过网线直连到笔记本有线，然后通过共享的无线进行上网。[link](http://jingyan.baidu.com/article/9158e00056cdc0a255122879.html)

	注意：断开有线(ip, dns设置为自动获取) --- 取消无线共享给有线 --- 开启无线共享给有线 --- 这时有线会自动变成192.168.137.1，以及相应的 掩码、网关、dns --- 网线连接树莓派


6.	扩展SD卡，识别剩余空间，否则浪费了

	```
	$ sudo raspi-config
	```
	
	会有BIOS一样的界面，比单纯ASC界面要图形界面一些

	查看空间容量

	```
	$ df -h
	```
	
	查看某个文件/文件夹的大小

	```
	$ du -sh xxx
	```	

6.	网络工具

	pi默认没有dig和nslookup，也不能直接用

	```
	$ sudo apt-get install dig
	```

	安装dnsutils

	```
	$ sudo apt-get install dnsutils
	```



7.	win->pi 传送文件，putty需要pscp

	进入cmd
	
	```
	d:\testfolder\pscp d:\testfolder\open.py pi@192.168.137.99:/home/pi/
	```

	第一项是pscp.exe地址;

	第二项是win上的文件地址;

	第三项 接收主机的 主机名@主机地址:/存放地址;

	存放地址要么留空，默认到家目录;
	
	但是不能直接写 ~ ，这样是识别出来的，需要/home/pi


	或者

	用python在要传输的目录下建立httpserver，然后回到putty，用curl/wget把需要的文件下载下来

	```
	$ wget 192.168.137.1:8000/xxx
	```

