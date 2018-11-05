// https://github.com/NodeRedis/node_redis

var redis = require("redis"),
client = redis.createClient();

client.on("error",function (err) {
    console.log("Open Client err:" + err);
});

client.set("node_test_key","value",redis.print);
client.hset("node_hash_key", "hashtest 1", "some value", redis.print);
client.hset(["node_hash_key", "hashtest 2", "some other value"], redis.print);
client.hkeys("node_hash_key", function (err, replies) {
    console.log(replies.length + " replies:");
    replies.forEach(function (reply, i) {
        console.log("    " + i + ": " + reply);
    });
    client.quit();
});