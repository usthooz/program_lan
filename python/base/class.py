class Test(object):
    count = 0
    def __init__(self,name):
        self.count +=1
        self.name = name
    def display(self):
        print "Count: %d" % self.count
        print "Name: %s" % self.name

t = Test("ooz")
t.display()


class Father(object):
    def __init__(self, name):
        self.name = name
        print("name: %s" % (self.name))

    def getName(self):
        return 'Father ' + self.name


class Son(Father):
    def getName(self):
        return 'Son ' + self.name


if __name__ == '__main__':
    son = Son('ooz')
    print(son.getName())
