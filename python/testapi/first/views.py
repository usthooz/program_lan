from django.shortcuts import render
from django.http import HttpResponse
from first.models import ooztest

# Create your views here.

def index(request):
    return HttpResponse("Hello, this is first.")

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