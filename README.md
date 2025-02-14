# leetcode_random_picker

本项目是leetcode热题一百刷题脚本，使用c++编写。



# 快速开始

直接使用release版本，下载后，运行：

```shell
chcp 65001 ; .\leetcode_random_picker.exe
```

当你需要重置你的题库时，直接删除生成的`question.json`即可。

# 手动编译

克隆本项目到本地，然后使用g++编译器编译：

```shell
cd randomLeetcode100
wget https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp
.\build.bat
chcp 65001 ; .\leetcode_random_picker.exe
```



# 附录Ⅰ：g++编译命令

编译过程使用 -c 参数选项

```shell
g++ -c main.cpp
g++ -c utils.cpp
```

链接过程使用 -o 参数选项

```shell
g++ -o leetcode_random_picker main.cpp utils.cpp
```

最后，直接在 leetcode_random_picker.exe 所在文件夹打开终端

```shell
.\leetcode_random_picker.exe
```

这样，就可以成功执行我们的程序了，不过麻烦了，不如使用 IDE 集成工具。如果将这些命令写到一个 .bat 批处理文件中，然后通过执行这个批处理文件，快速得到可执行程序。

```shell
del leetcode_random_picker.exe
g++ -c utils.cpp main.cpp
g++ -o leetcode_random_picker utils.o main.o
del main.o
del utils.o
.\leetcode_random_picker.exe
```

本项目使用的具体指令见`build.bat`。

# 附录Ⅱ：中文乱码情况

乱码产生应该是编码和解码所使用的字符集不同而导致的。我们就不得不提到 utf-8 和 gbk 两种我们常用的字符集了，前者也成为万国码，而后者则是国家标准。
windows系统安装后，我们选择语言时选择了简体中文，那么编码集就是 gbk。

可有时我们也会看到我们有些文件的编码是 ANSI，可以ANSI不是美国的国标么，为什么在这个标准下我们的中文也能够支持，哎，这就不得不提到，ANSI在中文里就是 gbk，如果在霓虹及，就是霓虹及的国标了。

我们使用命令行时，命令行中的编码也应该是  ANSI 即 gbk，命令行执行 leetcode_random_picker.exe 的过程就可以理解为解码过程，那么，很容易得出，解码使用 gbk 出错，因为编码的字符集是 utf8。

g++ 编译器编译文件时，默认就是选择使用 utf8 进行编码，那么得到的文件应当使用 utf8 进行解码才能实现咯，而我们选择的命令行默认使用了 gbk，自然无法得到正确的结果，从这个角度出发，就有了第一种解决方案

完全使用GBK编码来保存代码：
参考EzTry中，完全使用GBK编码，直接编译，exe文件运行没有中文乱码。
将全部代码文件编码模式全部改成GBK，编译运行，但出现一个问题，运行过程中会对question.json文件进行创建和修改，而这个默认是用UTF-8进行的。这会导致编码格式不统一，输出仍是乱码。


使用编译器选项：

在编译时，可以通过添加 -fexec-charset=GBK 选项来指定生成的可执行文件使用 GBK 编码。例如：
g++ -finput-charset=UTF-8 -fexec-charset=GBK %SOURCE_FILES% -o %OUTPUT_FILE% %INCLUDE_PATH% %COMPILE_FLAGS% 
但是在执行时出错，似乎无法从UTF-8转到GBK格式。

更换命令行的解码字符集

查看命令行的解码字符集命令为chcp，而更换更换为 utf8 ：
chcp 65001
更换为GBK：
chcp 936
值得注意的是，更换字符集仅对当前行命令有效，换句话说，要将执行的命令跟在这条语句后：
chcp 65001 && .\leetcode_random_picker.exe
或
chcp 65001 ; .\leetcode_random_picker.exe

