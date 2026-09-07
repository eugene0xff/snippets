# kata "Problems with deletions"
text:
```  
words words words              
text text text
new_text new_text new_text
new_new_text new_new_text new_new_text
```

kata:
- ESC
- `gg`, `dw`, `dw`, `u`, `u`
- `gg`, `d2w`, `u`
- `gg`, `dw`, `dw`, `U`
- `2gg`, `dd`, `u`
- `3gg`, `2dd`, `u`
- `3gg`, `dd`, `dd`, `"2p`, `"1p`
