import pytest
from main import curry, uncurry

def sum3(x, y, z):
    return x + y + z

def test_sum3_curry_uncurry():
    sum3_curry = curry(sum3, 3)
    sum3_uncurry = uncurry(sum3_curry, 3)
    print(sum3_curry(1)(2)(3))    # 6
    print(sum3_uncurry(1, 2, 3))  # 6
    assert sum3_curry(1)(2)(3) == 6
    assert sum3_uncurry(1, 2, 3) == 6
    assert sum3_curry(1)(2)(3) == sum3_uncurry(1, 2, 3)

def test_curry_zero_arity():
    def f():
        return "hello"
    result = curry(f, 0)
    assert result() == "hello"

def test_curry_negative_or_nonint():
    with pytest.raises(ValueError):
        curry(sum3, -1)
    with pytest.raises(TypeError):
        curry(sum3, "3")

def test_uncurry_wrong_args_number():
    def f(a):
        return a
    curried = curry(f, 1)
    uncurried = uncurry(curried, 1)
    with pytest.raises(ValueError):
        uncurried(1, 2)

def test_uncurry_negative_or_nonint():
    def f(x):
        return lambda y: x + y
    with pytest.raises(ValueError):
        uncurry(f, -1)
    with pytest.raises(TypeError):
        uncurry(f, "2")
