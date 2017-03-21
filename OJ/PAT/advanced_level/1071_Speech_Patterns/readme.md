##	[原题](https://www.patest.cn/contests/pat-a-practise/1022)：1071. Speech Patterns (25)

People often have a preference among synonyms of the same word. For example, some may prefer "the police", while others may prefer "the cops". Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.

Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word?

###	Input Specification

Each input file contains one test case. For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return '\n'. The input contains at least one alphanumerical character, i.e., one character from the set [0-9 A-Z a-z].

###	Output Specification

For each test case, print in one line the most commonly occurring word in the input text, followed by a space and the number of times it has occurred in the input. If there are more than one such words, print the lexicographically smallest one. The word should be printed in all lower case. Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non-alphanumerical characters or the line beginning/end.

Note that words are case insensitive.

###	Sample Input

	Can1: "Can a can can a can?  It can!"

###	Sample Output

	can 5

###	注意

	时间限制： 300 ms
	内存限制： 65536 kB
	代码长度限制： 16000 B
	判题程序： Standard
	作者： CHEN, Yue

<br/><br/>

#	题目分析



#	部分测试用例

同输入样例

#	其他参考

*	[cpp reference: map](http://www.cplusplus.com/reference/map/map/?kw=map)

*	[cpp reference: set](http://www.cplusplus.com/reference/set/set/?kw=set)

*	晴神宝典

*	同类题目互联

	[PAT_A_1054](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1054_The_Dorminat_Color)  
	[PAT_A_1071](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1071_Speech_Patterns)  
	[PAT_A_1022](https://github.com/jJayyyyyyy/cs/tree/master/OJ/PAT/advanced_level/1022_Digital_Library)

*	// TODO 更多同类题目互联

// TODO2, 整理以下内容


else{
	if( s.length()>0 ){
		if( word.find(s)!=word.end() ){
			word[s]++;
		}else{
			word[s] = 1;
		}
	}
	break;
}
		
		
cin.get() is equivalent to getchar()




test cases

Can1: "Can a can can a can?  It can!"

a 2
can 5
can1 1
it 1


a 123 123 123 a


a 123 123





reference


http://www.cplusplus.com/reference/istream/istream/get/?kw=cin.get

http://www.cplusplus.com/forum/beginner/34329/

https://www.quora.com/What-is-the-C++-equivalent-of-get-char-in-C