#!/usr/bin/python3
# _*_coding:utf-8_*_

import requests
import re
import codecs
from bs4 import BeautifulSoup
from openpyxl import Workbook
import random

userAgents = [
    "Mozilla/5.0 (compatible, MSIE 10.0, Windows NT, DigExt)",
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
    "MQQBrowser/26 Mozilla/5.0 (Linux, U, Android 2.3.7, zh-cn, MB200 Build/GRJ22, CyanogenMod-7) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1"
]

wb = Workbook()
ws1 = wb.active
ws1.title = "opencv.org首页内容"
DOWNLOAD_URL = 'http://www.opencv.org.cn/opencvdoc/2.3.2/html/doc/tutorials/tutorials.html'
dest_filename = 'opencv_home.xlsx'

# 请求页面url获取到页面内容
def download_page(url):
    randUa = random.sample(userAgents,1)
    headers = {
        'User-Agent': randUa[0]
    }
    data = requests.get(url, headers=headers).content
    return data


def get_li(doc):
    soup = BeautifulSoup(doc, 'html.parser')
    ol = soup.find('ul')
    # 标题
    title = []
    # 图片链接
    img_url = []
    # 跳转链接
    link = []
    # 描述
    info_list = []
    for i in ol.find_all('li'):
        detail = i.find('div', attrs={'class': 'hd'})
        article_title = detail.find(
            # 文章标题
            'span', attrs= {
                'class': 'first'
            }).get_text()
        img_info = i.find(
            # 图片
            'span', attrs= {
                'class': 'core Icon'
            }).get_text()
        link = i.find('div', attrs={'class': 'star'})
        # 图片
        info_list = star.find(text=re.compile('core Icon'))
        # 描述
        info = i.find('span', attrs={'class': 'first last'})
        # 判断是否有描述
        if info:
            info_list.append(info.get_text())
        else:
            info_list.append('Non!')
        score.append(level_star)

        title.append(title)
        img_url.append(img_info)
        # 获取下一页
    page = soup.find('span', attrs={'class': 'next'}).find('a')
    if page:
        return title, img_url, link, info_list, DOWNLOAD_URL + page['href']
    return title, img_url, link, info_list, None


def main():
    url = DOWNLOAD_URL
    title = []
    img_url = []
    link = []
    info = []
    while url:
        doc = download_page(url)
        a_title, img, linka, info, url = get_li(doc)
        title = title + a_title
        img_url = img_url + img
        link = link + linka
        info = info + info_list
    for (i, m, o, p) in zip(title, img_url, link, info):
        col_A = 'A%s' % (name.index(i) + 1)
        col_B = 'B%s' % (name.index(i) + 1)
        col_C = 'C%s' % (name.index(i) + 1)
        col_D = 'D%s' % (name.index(i) + 1)
        ws1[col_A] = i
        ws1[col_B] = m
        ws1[col_C] = o
        ws1[col_D] = p
    wb.save(filename=dest_filename)

if __name__ == '__main__':
    main()