#!/usr/bin/python3

dict = {'Name': 'ooz', 'Age': 1, 'Class': 'First'}

print("dict['Name']: ", dict['Name'])
print("dict['Age']: ", dict['Age'])

# 访问元素错误
# print("dict[ooz]:", dict['ooz'])

# 修改元素
dict['Name'] = 'usthooz'
print("dict['Name']:",dict['Name'])

# 删除键 'Name'
del dict['Name']
# 清空字典
dict.clear()
# 删除字典
del dict

# 注： 键是唯一的，元素可以为数字，字符串以及元组，但是不能是列表
