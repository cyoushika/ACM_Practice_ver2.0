# 前言
这是一个用于记录ACM题目以及总结经验和心得的分支,使用的参考书是《挑战程序设计大赛》（第二版）

习题册为[yogykwan大佬](https://github.com/yogykwan/acm-challenge-workbook)的git。

2012年开始接触ACM，仅仅坚持了一年就因为学业和个人原因放弃。时隔6年，想要重新拾起ACM，算是拓展自己，以及为过去的事情赎罪吧。。

因为太久没有接触C和C++的东西了，有些生疏，所以除了上面的挑战程序设计大赛，再加一本算法竞赛入门经典，来回顾一下C和C++的一些内容，基础的知识可能会稍微带一下，不会详细记述，着重记录已经忘记的，生疏的，或者压根不知道的内容。

## 题库
- Peking University Online Judge ([POJ](http://poj.org/))
- Aizu Online Judge ([AOJ](http://judge.u-aizu.ac.jp/onlinejudge/index.jsp?lang=en))

# 《算法竞赛入门经典》部分
### 关于printf
- printf输出Double浮点数的时候，使用的是%f而不是%lf
- 在规定显示小数点之后多少位的时候，可以使用%.(数字)f
- 在需要显示前置0的时候，例如需要输出025，可以使用%03d，用来表示输出一个3位整数且前置0需要显示
- 不要输出多余的信息，只会画蛇添足

### 关于常用到的Math库函数
- sqrt(数字) = 根号下（数字），输出该数字的算数平方根
- 圆周率π的表达方式，除了3.1415926以外，还有更精确的acos(-1.0),利用反三角函数得到π的值
- floor(x)返回不超过x的最大整数
- 25的阶乘有6个0

### 关于long long(64位整数)
- 因为竞赛当中经常会遇到int位数不够大（大概范围是-2147483648~+2147483648），无法存放下结果的情况，可以使用long long来代替int，声明一个64位整数
- 在使用long long的时候，输入和输出里的%d也需要更改，在Linux环境下是%lld，而在Windows环境下则是%I64d（而在VC2008里又改回了lld），为了避免这种问题，可以采用C++的输入流（cin)和输出流(cout)

### 关于文件操作
- freopen("input.txt","r",stdin),从input.txt文件中读取内容
- freopen("output.txt","w",stdout),将结果写入到output.txt文件中
- 可以通过#define XXX和#ifdef XXX, (文件操作) #endif的方式进行本地测试，上传代码之前删掉define的部分即可。XXX代表任意
- 如果比赛禁止重定向，则可以使用下面的方式进行读写:`FILE \*fin, \*fout; fin = fopen("data.in","rb"); fout = fopen("data.out","wb");`
- 如果使用上面的方法读，scanf("%d",&a)需要转换成fscanf(fin,"%d",&a)
- 如果使用上面的方法写，printf("%d\\n",a)需要转换为fprintf(fout,"%d\\n",a);
- 结束后需要关闭文件流，fclose(fin); fclose(fout);

# 第二章:初出茅庐，初级篇
## 穷竭搜索
所谓穷竭搜索，就是把所有的可能性都列出来，选出答案。
- 深度优先搜索(Depth First Search):搜索到无法继续搜索的时候退一步，继续搜索，直到所有结果都被遍历。
    - [x] [POJ2386](http://poj.org/problem?id=2386)
    - [x] [POJ1979](http://poj.org/problem?id=1979)
    - [x] [AOJ0118](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0118)
    - [x] [POJ1321](http://poj.org/problem?id=1321)
    - [x] [AOJ0033](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0033)
    - [x] [POJ3009](http://poj.org/problem?id=3009)
    - [] [POJ1190](http://poj.org/problem?id=1190)
