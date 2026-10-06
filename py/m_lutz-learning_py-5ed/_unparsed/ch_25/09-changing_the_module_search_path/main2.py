import sys
import traceback

sys.path = [r'd:\temp']
sys.path.append('c:\\lp5e\\example')
sys.path.insert(0, '..')
print(sys.path)

try:
    import string
    assert False
except ModuleNotFoundError as e:
    assert True
    print('--- [exception has been raised] ---')
    traceback.print_exc()
    print('-----------------------------------')

