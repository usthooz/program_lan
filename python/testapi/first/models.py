from django.db import models

# Create your models here.

class ooztest(models.Model):
    id = models.AutoField(primary_key=True)
    name = models.CharField(max_length=20)
    deleted = models.IntegerField(default=0)