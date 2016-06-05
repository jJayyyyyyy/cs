1. 替换掉keyfrom和key

2. 运行脚本后，输入想要翻译的词，返回翻译后的词。中英互译。推荐用来快速查英文单词，中文以及更复杂的更完整的去网上找。

3. 提交过长的短语或句子时，返回的json里面不一定有`'basic'`，会出现error。但是`'translation'`是一定有的，而一个单词的时候`'translation'`可能出现变成原文的情况。因此用`try-except`

4. 参考

[url中文编码](https://www.zhihu.com/question/22899135)

[try-except](http://www.cnblogs.com/taceywong/p/4859278.html)

[youdao api](http://fanyi.youdao.com/openapi?path=data-mode)

