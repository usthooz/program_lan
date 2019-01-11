#!/usr/bin/python3
# coding=utf-8

import time;
import calendar;

a = 21
b = 10
c = 0

if  a == b :
    print "1 - a 等于 b"
else:
    print "1 - a 不等于 b"

if  a != b :
    print "2 - a 不等于 b"
else:
    print "2 - a 等于 b"

if  a <> b :
    print "3 - a 不等于 b"
else:
    print "3 - a 等于 b"

if  a < b :
    print "4 - a 小于 b"
else:
    print "4 - a 大于等于 b"

if  a > b :
    print "5 - a 大于 b"
else:
    print "5 - a 小于等于 b"

# 修改变量 a 和 b 的值
a = 5
b = 20
if  a <= b :
    print "6 - a 小于等于 b"
else:
    print "6 - a 大于  b"

if  b >= a :
    print "7 - b 大于等于 a"
else:
    print "7 - b 小于 a"


a = 60            # 60 = 0011 1100
b = 13            # 13 = 0000 1101
c = 0

c = a & b;        # 12 = 0000 1100
print "1 - c 的值为：", c

c = a | b;        # 61 = 0011 1101
print "2 - c 的值为：", c

c = a ^ b;        # 49 = 0011 0001
print "3 - c 的值为：", c

c = ~a;           # -61 = 1100 0011
print "4 - c 的值为：", c

c = a << 2;       # 240 = 1111 0000
print "5 - c 的值为：", c

c = a >> 2;       # 15 = 0000 1111
print "6 - c 的值为：", c

print time.time()
print time.localtime(time.time())

# 格式化成2016-03-20 11:45:39形式
print time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())

# 格式化成Sat Mar 28 22:24:24 2016形式
print time.strftime("%a %b %d %H:%M:%S %Y", time.localtime())

# 将格式字符串转换为时间戳
a = "Sat Mar 28 22:24:24 2016"
print time.mktime(time.strptime(a,"%a %b %d %H:%M:%S %Y"))

time.sleep(1)

cal = calendar.month(2019, 1)
print "以下输出2019年1月份的日历:"
print cal

def printStr(str):
    print  str

printStr(time.time())


# 不定长参数
def printinfo( arg1, *vartuple ):
    print arg1
    for var in vartuple:
        print var
    return;

# 调用printinfo 函数
printinfo( 10 );
printinfo( 70, 60, 50 );

sum = lambda arg1, arg2: arg1 + arg2;
# 调用sum函数
print "相加后的值为 : ", sum( 10, 20 )
print "相加后的值为 : ", sum( 20, 20 )

def sum( arg1, arg2 ):
    total = arg1 + arg2
    print "函数内 : ", total
    return total;

# 调用sum函数
total = sum( 10, 20 );


try:
    fh = open("testfile", "w")
    fh.write("这是一个测试文件，用于测试异常!!")
except IOError:
    print "Error: 没有找到文件或读取文件失败"
else:
    print "内容写入文件成功"
    fh.close()

try:
    fh = open("testfile", "w")
    try:
        fh.write("这是一个测试文件，用于测试异常!!")
    finally:
        print "关闭文件"
        fh.close()
except IOError:
    print "Error: 没有找到文件或读取文件失败"