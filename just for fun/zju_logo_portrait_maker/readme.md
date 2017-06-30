##	Dependence

```bash
$ pip3 install pillow
```
	
##	Usage

```bash
$ python3 portrait_maker.py portrait.jpg
```

where [portrait.jpg] is any type of image as an input, whose size is better to be larger than 600*600.
	
## Workflow

1.  make the input file `portrait.jpg` a square image by adding white space.

2.  resize the image to `640*640`

3.  expand the image to `800*800` by adding white space as its frame

4.  process `logo.png` to get a circle with radius of 100

5.  paste the processed logo onto the bottom-right of the portrait image(that has a white frame)

    ps: the out-of-radius part of the logo has a special alpha value, so it won't be pasted onto the portrait

There is also a [demo](https://github.com/jJayyyyyyy/cs/tree/master/just%20for%20fun/zju_logo_portrait_maker/demo) folder which could help describe the workflow.

##  Reference

*   [alpha band](http://blog.csdn.net/robinzhou/article/details/6960345)

*   [cut a circle](http://www.webtag123.com/python/43461.html)
    
    ps: only part 1 of this page is useful

*   [PIL intro](http://www.cnblogs.com/way_testlife/archive/2011/04/17/2019013.html)

*   [PIL intro2](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/0014320027235877860c87af5544f25a8deeb55141d60c5000)

*   [pillow docs](https://python-pillow.org/)

*   [pillow docs2](http://pillow.readthedocs.io/en/4.1.x/index.html)