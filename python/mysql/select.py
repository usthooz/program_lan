#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import MySQLdb

def get_data(start_timestamp, end_timestamp):
    db_host = "127.0.0.1"
    user = "ooz"
    passwd = "ooz"
    port = 3306
    db = MySQLdb.connect(
        host=db_host, user=user, passwd=passwd, db="ooz_test", port=port)
    cursor = db.cursor()

    # total all
    total_orders_sql = r'select count(1) from `test` where `ts`>={start_timestamp} and `ts`<{end_timestamp}'.format(
        start_timestamp=start_timestamp, end_timestamp=end_timestamp)
    # total success
    total_success_sql = r'select count(1) from `test` where `ts`>={start_timestamp} and `ts`<{end_timestamp} and `status`=1'.format(
        start_timestamp=start_timestamp, end_timestamp=end_timestamp)

    cursor.execute(total_orders_sql)
    total_orders = cursor.fetchone()

    cursor.execute(total_success_sql)
    total_success = cursor.fetchone()

    cursor.close()

    result = "total_orders:{total_orders}\ntotal_success:{total_success}\n".format(
        total_orders=total_orders[0], total_success=total_success[0])

    return result


if __name__ == "__main__":
    # 获取数据
    data = get_data(1552320000, 1552406400)
    print(data)
