package main

import (
	"io"
	"log"
	"net/http"
)

func main() {
	// 路由规则
	http.HandleFunc("/hello")
	//启动端口的监听
	err := http.ListenAndServe(":8080", nil)
	//异常处理
	if err != nil {
		log.Fatal(err)
	}
}

func hello(rsp http.ResponseWriter, req *http.Request) {
	io.WriteString(rsp, "hello")
}
