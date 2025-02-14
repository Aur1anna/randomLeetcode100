# leetcode_random_picker

本项目是leetcode热题一百**随机抽题**脚本，仅供娱乐或参考😊。

使用c++编写。

运行时，会从Leetcode热题一百中随机无重复抽题。

抽题记录会以`question.json`保存在项目本地，以保持完成情况的记忆性。

# 快速开始

直接使用release版本，下载后，运行：

```shell
chcp 65001 ; .\leetcode_random_picker.exe
```

如果直接运行，会导致命令行输出的中文编码错误。做过的一些尝试如附录Ⅱ。

欢迎指出解决方案（如果有人看的话🤣）

这种方法无法调整题库信息，当你需要重置题库的完成情况时，直接删除生成的`question.json`即可。

# 手动编译

克隆本项目到本地，然后使用g++编译器编译：

```shell
cd randomLeetcode100
wget https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp
.\build.bat
chcp 65001 ; .\leetcode_random_picker.exe
```

如果你需要调整题库的内容、网址地址、题目是否做过等信息，请在`question_database.cpp`内手动修改后在本地重新编译。

# 附录Ⅰ：g++编译

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

乱码产生应该是编码和解码所使用的字符集不同而导致的。 utf-8 和 gbk 是两种我们常用的字符集，前者万国码，而后者则是国家标准。
windows系统安装后，如果选择语言时选择了简体中文，那么编码集就是 gbk。ANSI在中文里同 gbk。

我们使用命令行时，命令行中的编码也应该是  ANSI 即 gbk，而代码编码的字符集是 utf8，编译之后命令行执行 leetcode_random_picker.exe ，输出的中文就会乱码。

尝试：

**完全使用GBK编码来保存代码：**
参考其他本地编译的代码，完全使用GBK编码，直接编译，exe文件运行没有中文乱码。
将全部代码文件编码模式全部改成GBK，编译运行，但出现一个问题，运行过程中会对question.json文件进行创建和修改，而这个默认是用UTF-8进行的。这会导致编码格式不统一，输出仍是乱码。

**使用编译器选项：**

在编译时，可以通过添加 -fexec-charset=GBK 选项来指定生成的可执行文件使用 GBK 编码。例如：

```shell
g++ -finput-charset=UTF-8 -fexec-charset=GBK %SOURCE_FILES% -o %OUTPUT_FILE% %INCLUDE_PATH% %COMPILE_FLAGS% 
```

但是在执行时出错，似乎无法从UTF-8转到GBK格式。（？）

**更换命令行的解码字符集：**

查看命令行的解码字符集命令为`chcp`，直接输出，得到当前命令行使用的解码方式。

在输出时，将其更换为 utf8 ：

```shell
chcp 65001
```

附上更换为GBK的代码：

```shell
chcp 936
```

更换字符集仅对当前行命令有效。所以，要把执行的命令跟在这条语句后：

```shell
chcp 65001 && .\leetcode_random_picker.exe
```

或

```shell
chcp 65001 ; .\leetcode_random_picker.exe
```

于是，就暂且用这种方法吧。😀
