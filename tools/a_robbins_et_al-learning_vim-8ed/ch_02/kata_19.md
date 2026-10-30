# kata "Inserting text"
text:
```  
With a screen editor you can
scroll the page.
With a screen editor you can
move the cursor.
```

kata:
- ESC
- `gg`, `w`, `a`, type "abc", ESC, `u`
- `gg`, `w`, `A`, type "abc", ESC, `u`
- `gg`, `w`, `i`, type "abc", ESC, `u`
- `gg`, `w`, `I`, type "abc", ESC, `u`

- `2gg`, `o`, type "abc", ESC, `u`
- `2gg`, `O`, type "abc", ESC, `u`

- `gg`, `w`, `s`, type "a", ESC
= `gg`, `w`, `S`, type "With a screen editor you can", ESC
- `gg`, `w`, `R`, type "a new screen editor you can", ESC

