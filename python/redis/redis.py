#!/usr/bin/python
# -*- coding: utf-8 -*-

import redis

def ios_check_add(ver, flag, keys):
    redis_host = "127.0.0.1"
    redis_port = 6379
    r = redis.Redis(host=redis_host, port=redis_port)
    if flag == "add":
        print("开始添加...")
        for key in keys:
            print("Added-> " + key + "", ver, r.sadd(key, ver))
    elif flag == "delete":
        print("开始删除...")
        for key in keys:
            print("Deleted-> " + key + "", ver, r.srem(key, ver))
    else:
        print("Params invalid.")
    print("Finished.")


if __name__ == "__main__":
    keys = ["test1", "test2", "test3"]
    # 在服务器上需要使用raw_input，python
    flag = input("输入操作类型(add/delete): ")
    mem = input("输入添加值: ")
    ios_check_add(mem, flag, keys)
