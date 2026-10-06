from unders import *
print(a, c)

try:
    print(_b)
    assert False
except NameError:
    assert True

import unders
assert unders._b = 2
print(unders._b)
