#/usr/bin/env python

'''
Created on 2013-8-29

@author: Wim
'''
import os

#pyList = []
#pyTuple = ()
#
#pyList = raw_input('Enter pyList is:')
#pyTuple = raw_input('Enter pyTuple is:')
#
#i = 0
#total = 0
#meanNum = 0
#while i < len(pyList):
#    total += int(pyList[i])
#    i += 1
#
#meanNum = float(total / len(pyList))
#print 'List total is:', total
#print 'List mean is:', meanNum
#
#
#
#
#total = 0
#meanNum = 0
#for i in range(0, len(pyTuple)):
#    total += int(pyTuple[i])
#    
#meanNum = float(total / len(pyTuple))
#print 'Tuple total is:', total
#print 'Tuple mean is:', meanNum
#
#
#
#
#i = 1
#while i:
#    num = raw_input('Enter num is 1-100:')
#    if int(num) > 0 and int(num) <= 100:
#        i = 0
#        print 'Num is:', num, type(num)
#        
#    else:
#        print 'Error, please input!'




class NumOperate(object):
    def __init__(self):
        self.switchResult(self)
    def inputNum(self):
        self.numOne = raw_input("Enter num one is:")
        self.numTwo = raw_input("Enter num two is:")
        self.numThree = raw_input("Enter num three is:")
        self.numFour = raw_input("Enter num four is:")
        self.numFive = raw_input("Enter num five is:")
    def calculateSum(self):
        self.numSum = (int(self.numOne) + int(self.numTwo) + int(self.numThree)\
                        + int(self.numFour) + int(self.numFive))
        return self.numSum
    def calculateMean(self):
        self.numMean = self.numSum / 5
        return self.numMean
    def switchResult(self, onOff = 0x11):
        while onOff:
            print """
            (1)output five nums sum:
            (2)output five nums mean:
            (x)logout
            """
            onOff = raw_input("Enter switch:")
            
            if onOff == "1":
                self.inputNum()
                print "Num sum is:\n%s\n" % (self.calculateSum())
                continue
            elif onOff == "2":
                self.inputNum()
                print "Num mean is:\n%s\n" % (self.calculateMean())
                continue
            elif onOff == "x":
                break
            else:
                pass

if __name__ == '__main__':
    os.system("cls")
    numCl = NumOperate()




