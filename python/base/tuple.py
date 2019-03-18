#!/usr/bin/python3

# 注：1. 元组使用小括号，列表使用方括号 2. 元组的元素不能修改 3. 元组中只包含一个元素时，需要在元素后面添加逗号，否则括号会被当作运算符使用

# 创建空元组
tup = ();

tup1 = (50,)
print(type(tup1))
tup2 = (50)
print(type(tup2))

tup3 = (1, 2, 3, 4, 5, 6, 7)
print("tup3[1]:", tup3[1])

# 连接元组
tup4 = tup3 + tup1
print(tup4)

# 删除元组
del tup4