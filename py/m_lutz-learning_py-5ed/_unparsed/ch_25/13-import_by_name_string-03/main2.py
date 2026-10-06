print('using the  "importlib.import_module" func')

import importlib
modname = 'string'
string = importlib.import_module(modname)
print(string)

assert True
print('ok')
