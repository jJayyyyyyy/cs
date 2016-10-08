## Usage:

`$ python3 py3_SimpleHTTPServerWithUpload.py`

然后在浏览器输入`http://[ip]:8000`就能上传或者下载文件了。注意把`[ip]`换成你的局域网ip。

<br/>

## Notes:

文件夹`./py2_SimpleHTTPServerWithUpload/`中存储了基于python2.7的模块，在此感谢[bones7456](http://luy.li/2010/05/15/simplehttpserverwithupload/)同学和[BUPTGuo](http://buptguo.com/2015/11/07/simplehttpserver-with-upload-file/)同学的成果～

由于python的2.7和3.4有较多不同特性，因此我根据以上两位同学的思路，重写了很多函数，制作了基于`python3.4`的版本。主要改动如下：

* 移除了`StringIO`，不使用`copyfile()`。需要传输的信息全都用`str`。处理完逻辑后，再用`utf-8`编码为`bytes`，放到`wfile`上进行网络传输。
直接将bytes(str经过utf-8编码后得到的)

* 修改`html`的部分标签顺序


<br/>

更多内容请看[这里](https://jjayyyyyyy.github.io/2016/10/07/python3%E9%87%8D%E5%86%99SimpleHTTPServerWithUpload.html)

