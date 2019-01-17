from django.urls from path
from . import views

urlpatterns = [
    path('',views.index,name='index')
]