![badge](https://img.shields.io/badge/Python-3.4%2B-brightgreen.svg)

##	Description

通过命令行参数登陆扇贝，获取小组成员当天的打卡情况

##	Dependence

```bash
$ pip3 install requests beautifulsoup4
```

##	Usage

```bash
$ python3 GetStatus.py [username] [passwd]
```

##	TODO

原来的设想是，结合ItChat，通过微信的Web API，定时自动发消息通知组员。

不过目前微信网页版的封锁比较严重，我的微信已经不能登录。

需要研究一下PC版微信的接口。
