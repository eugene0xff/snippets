# Kata - Deleting words
text:
```
Screen editors are are very popular,
since they allowed you to make
since they allowed you to make
changes as you rReEaAdD through a file.
changes as you read through a file.
changes as you read through a file.
this doesn't compute.
```

kata:
- Esc
- `gg` (`1gg`) (`1G`), `2w`, `dw`
- `2gg` (`2G`), `/ed`, Enter, `dw`, `i`, type " ", Esc
- `3gg` (`3G`), `/ed`, Enter, `de`
- `4gg` (`4G`), `4w`, `db`, `i`, type "read ", Esc
- `5gg` (`5G`), `3w`, `d0`, `i`, type "changes as you ", Esc
- `6gg` (`6G`), `3w`, `d$`, `i`, type " read through a file.", Esc
- `7gg` (`7G`), `w`, `dw`, `u`
- `7gg` (`7G`), `w`, `dW`, `u`
