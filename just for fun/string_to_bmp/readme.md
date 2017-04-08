### **Make an Image out of a string of string**

##  Intro

*   Inspired by [KaitoHH: AnyCodeToBmp](https://github.com/KaitoHH/AnyCodeToBmp).

*   `strImage_init_demo.py` is a simplified version of [AnyCodeToBmp](https://github.com/KaitoHH/AnyCodeToBmp) based on Python3.4, which takes no command_line argument and simply encode the following string

    ```
    hello world.    
    ```
    
    into this BMP image:
    
    ![bmp](https://github.com/jJayyyyyyy/cs/raw/master/just%20for%20fun/string_to_bmp/expanded_demo1.bmp)

*   `strImage.py` is an updated version, which converts the file named `argv[1]` to a BMP. For example, if we choose the `ym_face` in this folder as `src`, 

    ```bash
    $ python3 strImage.py ym_face
    ```
    
    then we'll get the image below:

    ![bmp]((https://github.com/jJayyyyyyy/cs/raw/master/just%20for%20fun/string_to_bmp/expanded_demo2.bmp))

*   Note that Chinese words is generally more colorful than pure alphanums.

*   To be updated...

##  ref

*   [Wikipedia: BMP](https://en.wikipedia.org/wiki/BMP_file_format)

*   [ASCII](http://www.96yx.com/tool/ASC2.htm)

*   bytes

    [Stack Overflow: int_to_bytes](http://stackoverflow.com/questions/21017698/converting-int-to-bytes-in-python-3)

    [Python Docs: bytes](https://docs.python.org/3/library/functions.html#bytes)

*   other

    [liaoxuefeng: 字符串和编码](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431918785710e86a1a120ce04925bae155012c7fc71e000)

    [PIL: Editing_Pixels](https://en.wikibooks.org/wiki/Python_Imaging_Library/Editing_Pixels)
    
    [liaoxuefeng: PIL](http://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/0014320027235877860c87af5544f25a8deeb55141d60c5000#0)

    [在线计算器](http://www.zxjsq.net/)