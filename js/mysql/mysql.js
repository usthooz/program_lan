// 加载mysql模块
var mysql = require('mysql');
// 创建数据库连接
var conn = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '0707',
    database: 'nodetest',
});

conn.connect();

conn.query('select count(1) from user', function (err, results) {
    if (err){
        console.log('[SELECT ERROR] - ',err);
        return;
    };
    console.log('results', results);
});

// insert
var insertSql = 'insert into user(name) values(?)'
var insertParams = ['node']
conn.query(insertSql, insertParams, function (err, results) {
    if (err) {
        console.log('[INSERT ERROR] - ', err);
        return;
    };
    console.log('---\n\nINSERT---');
    console.log(results);
    console.log('---END---\n\n');
});

// select
var sql = 'select *from user'
conn.query(sql,function (err,results) {
    if (err){
        console.log('[SELECT ERROR] - ', err);
        return;
    };
    console.log('---SELECT---');
    console.log(results);
    console.log('---END---\n\n');
});


// update
var updateSql = 'update user set name=? where id=?';
var updateParams = ['nodetest',3];
conn.query(updateSql,updateParams,function (err,results) {
    if (err) {
        console.log('[UPDATE ERROR] - ', err.message);
        return;
    }
    console.log('---UPDATE---');
    console.log('UPDATE affectedRows', results.affectedRows);
    console.log('------\n\n');
});

// delete
var deleteSql = 'delete from user where id=?';
var deleteParams = [5];
conn.query(deleteSql,deleteParams,function (err,results) {
    if (err) {
        console.log('[DELETE ERROR] - ', err.message);
        return;
    }
    console.log('---DELETE---');
    console.log('DELETE affectedRows', results.affectedRows);
    console.log('------\n\n');  
});