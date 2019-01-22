### 使用Django创建api
- 安装

```
1. git clone https://github.com/django/django.git
2. cd django
3. python setup.py install
```
- 创建项目

```
1. django-admin.py startproject testapi
```

- 运行项目

```
1. python manage.py runserver / python manage.py runserver port(指定端口号)
```

- 添加逻辑

```
1. python3.7 manage.py startapp first
```

- 添加model
1. 在settings.py文件添加数据库连接信息

```
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'ooz', // 数据库
        'USER': 'root', // 用户名
        'PASSWORD': '', // 密码
        'HOST': '127.0.0.1', // 地址
        'PORT': '3306', // 端口
    }
}
```

2. 在first/models.py中添加表结构

```
class ooztest(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=20)
    deleted = models.IntegerField(default=0)
```

3. 依次执行命令

```
python manage.py migrate   # 创建表结构
python manage.py makemigrations first  # 让 Django 知道我们在我们的模型有一些变
更
python manage.py migrate first   # 创建表结构
```

3. 增加数据库操作views.py

```
def insert(request):
    test1 = ooztest(name='usthooz')
    test1.save()
    return HttpResponse("insert success...")

def list(request):
    response = ""
    response1 = ""
    list = ooztest.objects.all()
    for var in list:
        response1 += var.name + ""
    response = response1
    return HttpResponse("<p>"+response+"</p>")
```

4. 增加router

```
urlpatterns = [
    path('', views.index, name='index'),
    path('insert/', views.insert, name='insert'),
    path('list/', views.list, name='list')
]
```