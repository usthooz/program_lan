package opencv

import (
	"fmt"
	"testing"
	"time"
)

func TestOpencv(t *testing.T) {
	ti := time.Now()
	Convert()
	elapsed := time.Since(ti)
	fmt.Println("爬取结束,总共耗时: ", elapsed)
}
