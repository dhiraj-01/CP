import sys, subprocess
from os import path

def Run(cmd):
    subprocess.run(cmd, shell = True, check = True)

def getExe(options):
    exe = "a.exe"
    for i in range(len(options) - 1):
        if options[i] == '-o':
            exe = options[i + 1]
            del options[i] # remove '-o'
            del options[i] # remove 'exe'
            break
    return exe

def showHelp():
    # print("please provide file path as an argument.")
    print("run <source file> <options>")
    print("languages : C, C++, Python or Java.\n")
    print("sample examples:")
    print("run 1.cpp")
    print("run 1.cpp -DDHIRAJ")
    print("run 1.py < input.txt")
    print("run 1.java < input.txt > output.txt")
    print("run 1.cpp -DDHIRAJ < input.txt > output.txt")

# print(sys.argv)
if(len(sys.argv) == 1):
    showHelp()
    sys.exit(0)

try:
    file_path = sys.argv[1]
    if not path.exists(file_path):
        print(file_path, "path of the file is Invalid :(")
        sys.exit(0)

    lang = file_path.split('.')[-1]
    options = []
    for i in range(2, len(sys.argv)):
        options.append(sys.argv[i])

    cmd = "echo language not supported :("
    
    if(lang == "cpp"):
        exe = getExe(options)
        options = " ".join(options)
        cmd = f'g++ -std=c++17 {options} "{file_path}" -o "{exe}" && "{exe}"'

    elif(lang == "c"):
        exe = getExe(options)
        options = " ".join(options)
        cmd = f'gcc {options} "{file_path}" -o "{exe}" && "{exe}"'

    elif(lang == "py"):
        options = " ".join(options)
        cmd = f'python "{file_path}" {options}'

    elif(lang == "java"):
        options = " ".join(options)
        cmd = f'javac {options} "{file_path}" && java Main'

    # print(cmd)
    Run(cmd)

except KeyboardInterrupt as e:
    sys.exit(0)