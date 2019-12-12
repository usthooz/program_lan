import os
import json
from flask import Flask, request, redirect
from werkzeug.utils import secure_filename

app = Flask(__name__, static_url_path='/static')

@app.route('/', methods=['GET'])
def index():
    return app.send_static_file('lesson1.html')

@app.route('/<lesson>', methods=['GET'])
def lesson(lesson):
    if lesson == "one":
        return app.send_static_file('lesson1.html')
    if lesson == "two":
        return app.send_static_file('lesson2.html')      

@app.route('/get_data_cnt/', methods=['GET'])
def get_data_cnt():
    path = './static/resdata/'
    files = os.listdir(path)
    fileList = {}
    for file in files:
        fileList[file] = []
        file_d = os.path.join(path, file)
        if os.path.isdir(file_d):
            fileNum = 0
            my_files = os.listdir(file_d)
            for file1 in my_files:
                fileNum = fileNum + 1
                file1_d = os.path.join(file, file1)
                fileList[file].append({"filename": file1, "path": path + file1_d})
    print(fileList)
    return json.dumps(fileList)

@app.route('/get_data/', methods=['GET'])
def get_data():
    path = './static/resdata/'
    files = os.listdir(path)
    fileList = {}
    for file in files:
        fileList[file] = []
        file_d = os.path.join(path, file)
        if os.path.isdir(file_d):
            my_files = os.listdir(file_d)
            for file1 in my_files:
                file1_d = os.path.join(file, file1)
                fileList[file].append({"filename": file1, "path": path + file1_d})
    return json.dumps(fileList)

if __name__ == '__main__':
    app.run(host="0.0.0.0")
