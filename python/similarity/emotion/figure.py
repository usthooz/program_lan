# coding:utf-8

import jieba
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import GaussianNB
from sklearn.ensemble import RandomForestClassifier
from sklearn.model_selection import train_test_split
from sklearn import metrics
import pandas as pd
import matplotlib.pyplot as plt

# 读入评论数据
evaluation = pd.read_excel('evaluation.xlsx')
# 展示数据前5行
evaluation.head()

# 读入自定义词
with open('words.txt', encoding='UTF-8') as words:
    my_words = [i.strip() for i in words.readlines()]

# 读入停止词
with open('stopwords.txt', encoding='UTF-8') as words:
    stop_words = [i.strip() for i in words.readlines()]

# 将自定义词加入到jieba分词器中
for word in my_words:
    # jieba.add_word(word)
    st = [i for i in jieba.cut(word) if i not in stop_words]
    # 切完的词用空格隔开
    words =' '.join(st)


# 基于切词函数，构造自定义函数
def cut_word(sentence):
    words = [i for i in jieba.cut(sentence) if i not in stop_words]
    # 切完的词用空格隔开
    result =' '.join(words)
    return(result)

# TFIDF权重(根据词频，选出高频的20个词)
tfidf = TfidfVectorizer(max_features=20)
# 文档词条矩阵
dtm = tfidf.fit_transform(words).toarray()
# 矩阵的列名称
columns = tfidf.get_feature_names()
# 将矩阵转换为数据框--即X变量
X = pd.DataFrame(dtm, columns=columns)
# 情感标签变量
y = evaluation.Emotion
# 将数据集拆分为训练集和测试集
X_train,X_test,y_train,y_test = train_test_split(X,y,train_size =0.8, random_state=1)

# 模型优度的可视化展现
fpr, tpr, _ = metrics.roc_curve(y_test, pred,pos_label=2)
auc = metrics.auc(fpr, tpr)
# 中文和负号的正常显示
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] =False
# 设置绘图风格
plt.style.use('ggplot')
# 绘制ROC曲线
plt.plot(fpr, tpr,'')
# 绘制参考线
plt.plot((0,1),(0,1),'r--')
# 添加文本注释
plt.text(0.5,0.5,'ROC=%.2f'%auc)
# 设置坐标轴标签和标题
plt.title('朴素贝叶斯模型的AUC曲线')
plt.xlabel('1-specificity')
plt.ylabel('Sensitivity')
# 去除图形顶部边界和右边界的刻度
plt.tick_params(top='off',right='off')
# 图形显示
plt.show()
