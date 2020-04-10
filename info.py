import sys
import os

try:
    fileName = sys.argv[1]

except:
    print('not enough arguments')

red = 0
blue = 0
green = 0

try:
    file = open('../' + 'hare.txt')
    for line in file:
        for letter in line:
            if letter.islower():
                red += 1
            elif letter.isupper():
                blue += 1
            elif letter.isnumeric():
                green += 1
            else:
                green += 1
    file.close()
    oFile = open("colorfile.txt", 'r')
    oFile.write(str(red) + '\n')
    oFile.write(str(green) + '\n')
    oFile.write(str(blue) + '\n')
    oFile.close()

except IOError:
    print('Could not find the file')
