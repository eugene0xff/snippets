# kata "Deleteing words"
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
- ESC
- `gg`, `2w`, `dw`
- `2gg`, `/ed`, ENTER, `dw`, `i`, type " ", ESC
- `3gg`, `/ed`, ENTER, `de`
- `4gg`, `4w`, `db`, `i`, type "read ", ESC
- `5gg`, `3w`, `d0`, `i`, type "changes as you ", ESC
- `6gg`, `3w`, `d$`, `i`, type " read through a file.", ESC
- `7gg`, `w`, `dw`, `u`
- `7gg`, `w`, `dW`, `u`


