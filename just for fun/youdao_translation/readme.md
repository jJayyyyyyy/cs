##	用法Usage

*	[申请](http://fanyi.youdao.com/openapi?path=data-mode)自己的有道翻译api，替换掉keyfrom和key。

*	用python3运行脚本后，输入想要翻译的词，返回翻译后的词。用于快速查英文单词，中文以及更复杂的更完整的还是推荐使用网页版词典。

*	提交过长的短语或句子时，返回的json里面不一定有`'basic'`，会出现error。但是`'translation'`是一定有的，而一个单词的时候`'translation'`可能出现变成原文的情况。因此用`try-except`。

##	参考Reference

[url中文编码](https://www.zhihu.com/question/22899135)

[try-except](http://www.cnblogs.com/taceywong/p/4859278.html)

[youdao api](http://fanyi.youdao.com/openapi?path=data-mode)

##	20170107更新Update

*	因为未知原因api无法使用了，参考[这里](https://github.com/ianva/vim-youdao-translater/blob/master/plugin/ydt.vim)给出的url，新增re提取xml大法，详细文章更新在[这里](https://jjayyyyyyy.github.io/2017/01/06/url_encoding.html)。

	新增的`translate_web_xml.py`不需要keyfrom和key，使用方法不变。不过也可以根据喜好，把命令行参数作为待查词。

