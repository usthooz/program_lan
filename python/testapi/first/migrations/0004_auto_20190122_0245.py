# Generated by Django 2.1.5 on 2019-01-22 02:45

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('first', '0003_auto_20190122_0244'),
    ]

    operations = [
        migrations.AlterField(
            model_name='ooztest',
            name='id',
            field=models.AutoField(primary_key=True, serialize=False),
        ),
    ]
