package opencv

import (
	"io/ioutil"
	"math/rand"
	"os"
	"regexp"
	"time"

	"github.com/swxctx/ghttp"
	"github.com/usthooz/oozlog/go"
)

type Swoop struct {
	url    string
	header map[string]string
}

// get_html_header
func (swoop Swoop) get_html_header() string {
	// new request
	req := ghttp.Request{
		Url:     swoop.url,
		Method:  "GET",
		Timeout: 1000 * time.Millisecond,
	}
	req.AddHeader("Accept-Encoding", "gzip")

	for key, value := range swoop.header {
		req.AddHeader(key, value)
	}
	resp, err := req.Do()
	if err != nil {
		ozlog.Fatalf("do client err->%v", err)
	}
	defer resp.Body.Close()
	body, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		ozlog.Fatalf("read resp err->%v", err)
	}
	return string(body)

}

func Convert() {
	header := map[string]string{
		"Host":                      "opencv.org.cn",
		"Connection":                "keep-alive",
		"Cache-Control":             "max-age=0",
		"Upgrade-Insecure-Requests": "1",
		"Accept":                    "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8",
		"Referer":                   "http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/tutorials.html",
	}
	// 随机获取user_agent，避免被封
	header["User-Agent"] = GetRandomUserAgent()

	//创建csv文件
	f, err := os.Create("./opencv.csv")
	if err != nil {
		panic(err)
	}
	defer f.Close()

	//写入
	f.WriteString("标题" + "\t" + "封面" + "\t" + "描述" + "\t" + "跳转链接" + "\t" + "\r\n")

	ozlog.Infof("开始抓取数据...")
	url := "http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/tutorials.html"
	swoop := &Swoop{url, header}
	html := swoop.get_html_header()

	//评价人数
	commentCount := `<em>(.*?)OpenCV介绍</em>`
	rp2 := regexp.MustCompile(commentCount)
	txt2 := rp2.FindAllStringSubmatch(html, -1)
	ozlog.Infof("标题: %v", txt2)

	// //评分
	// pattern3 := `property="v:average">(.*?)</span>`
	// rp3 := regexp.MustCompile(pattern3)
	// txt3 := rp3.FindAllStringSubmatch(html, -1)

	// //电影名称
	// pattern4 := `img width="(.*?)" alt="(.*?)" src=`
	// rp4 := regexp.MustCompile(pattern4)
	// txt4 := rp4.FindAllStringSubmatch(html, -1)

	f.WriteString("\xEF\xBB\xBF")

	// for i := 0; i < len(txt2); i++ {
	// 	fmt.Printf("%s %s %s\n", txt4[i][1], txt3[i][1], txt2[i][1])
	// 	f.WriteString(txt4[i][2] + "\t" + txt3[i][1] + "\t" + txt2[i][1] + "\t" + "\r\n")
	// }
}

var userAgent = [...]string{"Mozilla/5.0 (compatible, MSIE 10.0, Windows NT, DigExt)",
	"Mozilla/4.0 (compatible, MSIE 7.0, Windows NT 5.1, 360SE)",
	"Mozilla/4.0 (compatible, MSIE 8.0, Windows NT 6.0, Trident/4.0)",
	"Mozilla/5.0 (compatible, MSIE 9.0, Windows NT 6.1, Trident/5.0,",
	"Opera/9.80 (Windows NT 6.1, U, en) Presto/2.8.131 Version/11.11",
	"Mozilla/4.0 (compatible, MSIE 7.0, Windows NT 5.1, TencentTraveler 4.0)",
	"Mozilla/5.0 (Windows, U, Windows NT 6.1, en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50",
	"Mozilla/5.0 (Macintosh, Intel Mac OS X 10_7_0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11",
	"Mozilla/5.0 (Macintosh, U, Intel Mac OS X 10_6_8, en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50",
	"Mozilla/5.0 (Linux, U, Android 3.0, en-us, Xoom Build/HRI39) AppleWebKit/534.13 (KHTML, like Gecko) Version/4.0 Safari/534.13",
	"Mozilla/5.0 (iPad, U, CPU OS 4_3_3 like Mac OS X, en-us) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.2 Mobile/8J2 Safari/6533.18.5",
	"Mozilla/4.0 (compatible, MSIE 7.0, Windows NT 5.1, Trident/4.0, SE 2.X MetaSr 1.0, SE 2.X MetaSr 1.0, .NET CLR 2.0.50727, SE 2.X MetaSr 1.0)",
	"Mozilla/5.0 (iPhone, U, CPU iPhone OS 4_3_3 like Mac OS X, en-us) AppleWebKit/533.17.9 (KHTML, like Gecko) Version/5.0.2 Mobile/8J2 Safari/6533.18.5",
	"MQQBrowser/26 Mozilla/5.0 (Linux, U, Android 2.3.7, zh-cn, MB200 Build/GRJ22, CyanogenMod-7) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1"}

var (
	r = rand.New(rand.NewSource(time.Now().UnixNano()))
)

func GetRandomUserAgent() string {
	return userAgent[r.Intn(len(userAgent))]
}
