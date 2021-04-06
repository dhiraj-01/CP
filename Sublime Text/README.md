## My Sublime Text setup for coding (C++ and Windows)

```
same steps can be followed for other languages
- Install sublime
- Install compiler for language
- Add build file for language
- ctrl + b to Run :)
```

### 1. MinGW Compiler 
* Install Mingw from https://sourceforge.net/projects/mingw/ or https://osdn.net/projects/mingw/releases/ 
* Youtube video : https://youtu.be/sXW2VLrQ3Bs 
* Your path should preferably be `C:\MinGW`. Finally, add the bin directory, `C:\MinGW\bin` to the System PATH.   
  (you can also change that path but make sure to add in System PATH, so that we can access `g++` from anywhere)

### 2. Sublime Text
* Install https://www.sublimetext.com/

### 3. Create a build system
* Open `Sublime > Go to Tools > Build System > New Build System`.
* Paste [this build](https://github.com/Dhiraj-01/CP/blob/main/Sublime%20Text/Build/C%2B%2B.sublime-build) in the file and save as `C++.sublime-build`.
* Select custom build `Tools > Build System > C++.sublime-build`.

### 4. Let's check
* write some code.
* select build for C++ language (`Sublime > Go to Tools > Build System > New Build System > C++.sublime-build`).
* `ctrl + b` to run your code (that logic is writtern in build file)
* `ctrl + shift + b` to navigate between build options

### 5. Infinite loop solution
* open terminal and paste `taskkill /IM a.exe /F`
* `ctrl + e` in sublime, for that `Preferences => key bindings` add this keyboard shortcut   
  `{ "keys": ["ctrl + e"], "command": "cancel_build" },`
* Task Manager `a.exe => end task`


[OdatNurd - Sublime Text Tutorials](https://www.youtube.com/channel/UCJAB_XF3kAMqwF85y0hxcXQ)
