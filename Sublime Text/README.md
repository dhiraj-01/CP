## My Sublime Text setup for coding (windows)

### 1. MinGW Compiler 
* Install Mingw from https://sourceforge.net/projects/mingw/ or https://osdn.net/projects/mingw/releases/ 
* Youtube video : https://youtu.be/sXW2VLrQ3Bs 
* Your path should preferably be `C:\MinGW`. Finally, add the bin directory, `C:\MinGW\bin` to the System PATH.   
  (you can also change that path but make sure to add in System PATH, so that we can access `g++` from anywhere)

### 2. Sublime Text
* Install https://www.sublimetext.com/

### 3. Create a build system for your language
* Open `Sublime > Go to Tools > Build System > New Build System`.
* Paste [build](https://github.com/Dhiraj-01/CP/tree/main/Sublime%20Text/Build) according to your language in the file and save as `language_name.sublime-build` (ex. `C++.sublime-build`)
* Select custom build `Tools > Build System > language_name.sublime-build`

### 4. Let's check
* write code in your language
* select build for that language (`Sublime > Go to Tools > Build System > New Build System`)
* `ctrl + b` to run your code (that logic is writtern in build file)
* `ctrl + shift + b` to navigate between build options

### 5. Infinite loop solution
* kill process by `taskkill /IM process_name /F`   
  ex. for C++ `taskkill /IM a.exe /F` (in terminal)   
* `ctrl + e` in sublime, for that `Preferences => key bindings` add this keyboard shortcut   
  `{ "keys": ["ctrl + e"], "command": "cancel_build" },`
* Task Manager `a.exe => end task` (C++)


[OdatNurd - Sublime Text Tutorials](https://www.youtube.com/channel/UCJAB_XF3kAMqwF85y0hxcXQ)
