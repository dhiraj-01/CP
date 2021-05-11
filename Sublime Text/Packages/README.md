## Custom packages sublime text

- **C++ Auto Complete** : auto complete for c++
- **Terminal** : open command prompt for current directory
- **File Explorer** : open file explorer for current directory
- **Compare** : comapre o1.txt and o2.txt
- **Quote** : add quote and user info in current file

### Use :
- copy all folder into `C:\Users\...\AppData\Roaming\Sublime Text 3\Packages`
- `Preferences => key bindings` add keyboard shortcut
```json
[
    { "keys": ["f5"], "command": "quote" },
    { "keys": ["f6"], "command": "compare"},
    { "keys": ["ctrl + `"], "command": "terminal" },
    { "keys": ["ctrl+shift+`"], "command": "file_explorer" },
]
```