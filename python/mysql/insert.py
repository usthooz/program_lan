#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import MySQLdb
import time

def add_data(name,uid,ts):
    db_host = "127.0.0.1"
    user = "ooz"
    passwd = "ooz"
    port = 3306
    database = "test"
    db = MySQLdb.connect(
        host=db_host, user=user, passwd=passwd, db=database, port=port)
    cursor = db.cursor()

    try:
        isql = "INSERT INTO card(name,uid,type,status,updated_at,created_at) VALUES ('%s','%d',4,1,'%d','%d')" % (
        str(couple_id), int(uid), int(ts), int(ts))
        cursor.execute(isql)
        db.commit()
        print("添加完成")        
    except:
        db.rollback()
        print("Insert err")
        raise
    finally:
        cursor.close()
        db.close()


if __name__ == "__main__":
    # 获取数据
    name = raw_input("Input name: ")
    uid = raw_input("Input uid: ")
    add_data(name, uid, int(time.time()))
