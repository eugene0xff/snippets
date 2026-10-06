from alls import *

assert a == 1 and _c == 3
print(a, _c)

try:
    print(b)
    assert False
except NameError:
    assert True
    print('error when importing all.b')
