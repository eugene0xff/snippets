# Kata - Deleteing lines
text:
```
Screen editors are are very popular,
since they allow you to make
changes as you read through a file.
```

kata:
- Esc
- `gg` (`1gg`) (`1G`), `dd`, `u`
- `gg` (`1gg`) (`1G`), `2dd`, `u`
- `3gg` (`3G`), `d$`, `i`, type " as you read through a file", Esc
- `3gg` (`3G`), `D`, `i`, type " as you read through a file", Esc
