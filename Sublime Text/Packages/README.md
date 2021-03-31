## Custom packages sublime text

- Cmd : open terminal for current directory
- Quote : add quote in current file
- C++AutoComplete : auto completion for cpp language

### Use :
- copy all folder into `C:\Users\...\AppData\Roaming\Sublime Text 3\Packages`
- `Preferences => key bindings` add keyboard shortcut
```json
[
    { "keys": ["f5"], "command": "quote" },
    { "keys": ["ctrl + `"], "command": "cmd" },
]
```