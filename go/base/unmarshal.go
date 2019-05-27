package main

import (
	"encoding/json"
	"fmt"
	"reflect"
	"strconv"

	"github.com/usthooz/oozlog/go"
)

type Test struct {
	AderId     string      `json:"ader_id"`
	Height     interface{} `json:"height"`
	Width      string      `json:"width"`
	TargetType int         `json:"target_type"`
}

type Resp struct {
	AderId     string      `json:"ader_id"`
	Height     interface{} `json:"height"`
	Width      interface{} `json:"width"`
	TargetType int         `json:"target_type"`
}

func main() {
	testt := &Test{
		AderId:     "1",
		Height:     nil,
		Width:      "960",
		TargetType: 3,
	}
	// marshal
	data, err := json.Marshal(testt)
	if err != nil {
		ozlog.Errorf("err-> %v", err)
		return
	}
	fmt.Println(string(data))

	// unmarshal
	var (
		resp *Resp
	)
	err = json.Unmarshal(data, &resp)
	if err != nil {
		ozlog.Errorf("err-> %v", err)
	}
	ozlog.Infof("h-> %d", InterfaceToInt32(resp.Height))
	ozlog.Infof("w-> %d", InterfaceToInt32(resp.Width))

}

// Int32ByInterface 反射取出数据
func InterfaceToInt32(v interface{}) int32 {
	var (
		res int64
		err error
	)
	vType := reflect.TypeOf(v)
	if vType == nil {
		return int32(res)
	}
	ozlog.Infof("vType-> %v", vType)
	switch vType.Name() {
	case "string":
		res, err = strconv.ParseInt(v.(string), 10, 64)
		if err != nil {
			ozlog.Errorf("err-> %v", err)
		}
	case "float64":
		res = int64(v.(float64))
	default:
		ozlog.Errorf("err->数据类型不正确")
	}
	return int32(res)
}
