package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"

	"github.com/usthooz/oozlog/go"
)

// 移除a文件中的b文件内容
func main() {
	// 样本(需要过滤掉的数据)
	f1, err := os.Open("enter_users.dat")
	if err != nil {
		panic(err)
	}
	defer f1.Close()

	// 已经参加活动的用户
	var (
		equs   map[string]string
		result map[string]string
	)
	ozlog.Infof("开始计算所有参加过活动的用户.")
	equs = make(map[string]string)
	rd := bufio.NewReader(f1)
	for {
		line, err := rd.ReadString('\n')
		if err != nil || io.EOF == err {
			break
		}
		line = strings.Replace(line, "\n", "", -1)
		equs[line] = line
	}

	ozlog.Infof("开始进行过滤操作.")
	// 所有数据
	f, err := os.Open("active_users.dat")
	if err != nil {
		panic(err)
	}
	defer f.Close()
	// 所有活跃的用户
	result = make(map[string]string)
	rd1 := bufio.NewReader(f)
	for {
		line, err := rd1.ReadString('\n')
		if err != nil || io.EOF == err {
			break
		}
		line = strings.Replace(line, "\n", "", -1)
		// 没有进入过活动
		if _, ok := equs[line]; !ok {
			result[line] = line
		}
	}
	ozlog.Infof("开始写入文件.")
	// 最终需要推送的用户
	err = WriteMaptoFile(result, "push_users.dat")
	if err != nil {
		ozlog.Errorf("写入文件失败.")
	}
	ozlog.Infof("任务执行完成.")
}

func WriteMaptoFile(m map[string]string, filePath string) error {
	f, err := os.Create(filePath)
	if err != nil {
		fmt.Printf("create map file error: %v\n", err)
		return err
	}
	defer f.Close()

	w := bufio.NewWriter(f)
	for _, v := range m {
		lineStr := fmt.Sprintf("%s", v)
		fmt.Fprintln(w, lineStr)
	}
	return w.Flush()
}
