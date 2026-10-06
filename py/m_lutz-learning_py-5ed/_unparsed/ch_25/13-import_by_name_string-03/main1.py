print('using the build-in "__import__" func')

modname = 'string'
string = __import__(modname)
print(string)

assert True
print('ok')
