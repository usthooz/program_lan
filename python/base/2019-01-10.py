#!/usr/bin/python3
# coding=utf-8

print("2019-10-10")
print("你好啊")

# check
if True:
    print("True")
else:
    print("False")

#raw_input("enter.\n")

a=1
b=2
print a
print b
print a,b

x=y=1
print x
print y
w,z=1,'dsff'
print w
print z

print z[0:1]
print z + 'hha'

list1 = [1,2,'a','b']
list2 = [5,6,7]
print list1
print list1 * 2
print list1 + list2

# only read
tuple = ('a','b', 'c', 1,3)
print tuple
print tuple[0:1]

# 字典
dict = {}
dict[1]=1
dict['a']=a
print dict[1]

tinydict = {'name': 'john','code':6734, 'dept': 'sales'}
print tinydict
print tinydict.keys()
print tinydict.values()
