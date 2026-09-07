# kata "Numerci arguments for insert commands"
text:
```  
||
With a screen editor you can
scroll the page.
With a screen editor you can
move the cursor.
```

kata:
- ESC
- `gg`, `O`, ESC, `50i*`, ESC, `u`
- `gg`, `25a*-`, ESC, `u`
- `gg`, `dd`

- `gg`, `2r&`

