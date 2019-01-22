from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('insert/', views.insert, name='insert'),
    path('list/', views.list, name='list'),
    path('cache_set/', views.cacheSet, name='cache_set'),
    path('cache_get/', views.cacheGet, name='cache_get')
]