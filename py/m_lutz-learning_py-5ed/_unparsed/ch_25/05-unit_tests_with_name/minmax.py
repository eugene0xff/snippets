print('i am:', __name__)

def minmax(test, *args):
    res = args[0]
    for arg in args[1:]:
        if test(arg, res):
            res = arg
    return res

def lessthan(x, y): return x < y
def greaterthan(x, y): return x > y

if __name__ == '__main__':
    val1 = minmax(lessthan, 4, 2, 1, 5, 6, 3)
    assert val1 == 1
    print(val1)

    val2 = minmax(greaterthan, 4, 2, 1, 5, 6, 3)
    assert val2 == 6
    print(val2)

