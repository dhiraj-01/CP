# compare two files

import sys
from os import system

# default file
file1 = "D:/dhiraj/Programming/o1.txt"
file2 = "D:/dhiraj/Programming/o2.txt"

if len(sys.argv) >= 3:
    file1 = sys.argv[1]
    file2 = sys.argv[2]

with open(file1, "r") as O1:
    o1_lines = O1.readlines()

with open(file2, "r") as O2:
    o2_lines = O2.readlines()

for i in range(len(o1_lines)):
    o1_lines[i] = o1_lines[i].strip()

for i in range(len(o2_lines)):
    o2_lines[i] = o2_lines[i].strip()

# remove extra empty lines from end
l1 = len(o1_lines) - 1
while(l1 >= 0 and o1_lines[l1] == ""):
    o1_lines.pop(l1)
    l1 -= 1

l2 = len(o2_lines) - 1
while(l2 >= 0 and o2_lines[l2] == ""):
    o2_lines.pop(l2)
    l2 -= 1

line_no = 0
diffrence = ""

l1 = len(o1_lines)
l2 = len(o2_lines)

while line_no < l1 or line_no < l2:
    #Read the next line from the file
    f1_line = f2_line = ''
    if(line_no < l1):
        f1_line = o1_lines[line_no]
    if(line_no < l2):
        f2_line = o2_lines[line_no]

    #Increment line counter
    line_no += 1

    # Compare the lines from both file
    if f1_line != f2_line:
        # If a line does not exist on file2 then mark the output with + sign
        if f2_line == '' and f1_line != '':
            diffrence += " -- {}\t{}\n".format(line_no, f1_line)
        # otherwise output the line on file1 and mark it with > sign
        elif f1_line != '':
            diffrence += "  - {}\t{}\n".format(line_no, f1_line)

        # If a line does not exist on file1 then mark the output with + sign
        if f1_line == '' and f2_line != '':
            diffrence += " ++ {}\t{}\n".format(line_no, f2_line)
        # otherwise output the line on file2 and mark it with < sign
        elif f2_line != '':
            diffrence += "  + {}\t{}\n".format(line_no, f2_line)

if(diffrence == ""):
    diffrence = "Both files are identical."
    print(diffrence)
else:
    print(diffrence)
    '''    
    if(1):
        print(diffrence)
    else:
        diff_file = "D:/dhiraj/Programming/Hacking/Files/diff.txt"
        with open(diff_file, "w") as file:
            file.write(diffrence)

        execute = f'start cmd /c \"more "{diff_file}" && pause\"'
        system(execute)
    '''