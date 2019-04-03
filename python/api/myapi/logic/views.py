from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def index(request):
    return HttpResponse("Hello, this is index.")

def figure(request):
    name = request.GET.get('name')
    return HttpResponse("Hello "+name+", this is figure.")
