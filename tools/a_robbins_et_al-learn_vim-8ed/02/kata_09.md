# kata "Substituting text"
text:
```
Text tTTt
2 text
3 text
4 text
5 text
```

kata:
- ESC
- `gg`, `s`, type "t", ESC
- `w`, `l`, `2s`, type "ex", ESC
- `2gg`, `S`, type "02 new text", ESC
- `3gg`, `2S`, type "03 new text<--CR-->04 new text", ESC
- `5gg`, `R`, type "05 new text", ESC





