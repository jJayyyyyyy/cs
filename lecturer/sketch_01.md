#   1. 框架

*	首先介绍python是什么（与计算机对话的工具，...）

*	第二，为什么要用python（简洁而强大）

*	如何用，能做哪些东西（体验与操作）

	1.	放一个游戏（贪吃蛇，飞机大战），让小朋友操作试玩

	2.	用bmp_maker（把文字转换成BMP图像）处理游戏代码，得到一张图片，用另一种方式展现这个游戏

	3.	再用文本编辑器打开图片，看到真实的代码，简单介绍一下逻辑

	4.	除此以外，还可以接入王老师的树莓派课程。我们可以组装一个小车，然后以树莓派作为中转服务器，我们可以在浏览器上(或者写一个简单的app)对小车进行遥控

		【浏览器---wifi---树莓派(flask)---gpio---[arduino---射频模块(发)---射频模块(收)---51/STM32---小电机---轮子---小车移动]】

*	最后为了玩这些，我们需要学哪些内容，python基础，...

<br/><br/>

#   2. 参考

*   [简单实现树莓派的WEB控制](http://www.cnblogs.com/yafengabc/archive/2016/02/18/5197844.html)

*   [Bootstrap](http://v3.bootcss.com/getting-started/#download)

*   [flask 1](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001432012745805707cb9f00a484d968c72dbb7cfc90b91000)

*   [flask 2](http://tieba.baidu.com/p/4086802846)

*   [Quboid, 翻转格子](https://github.com/tobspr/RenderPipeline)

*   [飞机大战 1](https://github.com/Kill-Console/PythonShootGame)

    ```
    $ pip install pygame
    $ python mainGame.py
    ```

*   [飞机大战 2](http://www.pythontab.com/html/2013/pythongui_0930/578.html)

*   [飞机大战 3](http://bbs.fishc.com/thread-59506-1-1.html)

*   [飞机大战 4](http://www.jb51.net/article/74425.htm)

*   [PIL 图像反色](http://blog.csdn.net/yockie/article/details/8498301)

    ```python3
    from PIL import Image, ImageChops
    img = Image.open('demo.bmp')
	i_img = ImageChops.invert(img)
	i_img.save('demo_b.bmp')
    ```

*   [bmp_maker](https://github.com/jJayyyyyyy/bmp_maker)
