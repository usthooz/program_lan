# Generated by Django 2.1.5 on 2019-01-22 02:44

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('first', '0002_auto_20190122_0240'),
    ]

    operations = [
        migrations.AlterField(
            model_name='ooztest',
            name='id',
            field=models.IntegerField(primary_key=True, serialize=False),
        ),
    ]
