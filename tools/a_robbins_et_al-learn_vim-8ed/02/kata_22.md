# kata "Review of editing"
text:
```  
text1 text2 text3 text4 text5
textA textB textC textD textE
```

kata:
- ESC
- `gg`, `cw`, type "newtext1", ESC, `u`
- `gg`, `dw`, `u`
- `gg`, `yw`, `$`, `p`, `u`, `P`, `u`

- `gg`, `c2W` (`2cW`), type "newtext1 newtext2", ESC, `u`
- `gg`, `d2W` (`2dW`), `u`
- `gg`, `y2W` (`2yW`), `$`, `p`, `u`, `P`, `u`

- `gg`, `$`, `c3b` (`3cb`), type "newtext3 newtext4 newtext5", ESC, `u`
- `gg`, `$`, `d3b` (`3db`), `u`
- `gg`, `y3b` (`3yb`), `$`, `p`, `u`, `P`, `u`

- `gg`, `$`, `cc`, type "newtext1 newtext2 newtext3 newtext4 newtext5", ESC, `u`	
- `gg`, `$`, `dd`, `u`
- `gg`, `$`, `yy`, `p`, `u`, `P`, `u`
- `gg`, `$`, `Y`, `p`, `u`, `P`, `u`

- `gg`, `4w`, `c$`, type "newtext5", ESC, `u`
- `gg`, `4w`, `C`, type "newtext5", ESC, `u`
- `gg`, `4w`, `d$`, `u`, `D`, `u`
- `gg`, `4w`, `y$`, `$`, `p`, `u`, `P`, `u`

- `gg`, `w`, `c0`, type "newtext1 ", ESC, `u`
- `gg`, `w`, `d0`, `u`
- `gg`, `w`, `y0`, `$`, `p`, `u`, `P`, `u`

- `gg`, `2l`, `r`, type "X", `u`
- `gg`, `2l`, `x`, `u`, `X`, `u`
- `gg`, `2l`, `yl`, `$`, `p`, `u`, `P`, `u`, `0`, `2l`, `yh`, `$`, `p`, `u`, `P`, `u`

- `gg`, `5s`, `abcde`, ESC, `u`
- `gg`, `5x`, `u`
- `gg`, `5l`, `5X`, `u`
- `gg`, `y5l` (`5yl`), `$`, `p`, `u`, `P`, `u`






