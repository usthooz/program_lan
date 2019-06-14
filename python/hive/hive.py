# -*- coding: utf-8 -*-
from pyhive import hive

conn = hive.Connection(
    host='127.0.0.1',
    port=10000,
    username='',
    password='',
    database='default',
    auth='LDAP')
cursor = conn.cursor()
cursor.execute('select * from test limit 10')
for result in cursor.fetchall():
    print result