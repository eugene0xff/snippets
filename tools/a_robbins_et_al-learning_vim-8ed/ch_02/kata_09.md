# Kata - Substituting text
text:
```
Text tTTt
2 text
3 text
4 text
5 text
```

kata:
- Esc
- `gg` (`1gg`) (`1G`), `s`, type "t", Esc
- `w`, `l`, `2s`, type "ex", Esc
- `2gg`, `S`, type "02 new text", Esc
- `3gg`, `2S`, type "03 new text<Enter>04 new text", Esc
- `5gg` (`5G`), `R`, type "05 new text", Esc
