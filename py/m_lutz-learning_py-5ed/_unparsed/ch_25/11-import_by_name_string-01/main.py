# here a syntax error will be
# import 'string'

print('naive approach to module import from a str var')

try:
    x = 'string'
    import x
    assert False
except ModuleNotFoundError:
    assert True

print('ok')
