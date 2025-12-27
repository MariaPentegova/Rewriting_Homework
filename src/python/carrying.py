def curry(func, n):
    if not isinstance(n, int):
        raise TypeError("Error! type(n)!=int")
    if n < 0:
        raise ValueError("Error! n<0")
    if n == 0:
        return func

    def start(initial_arg):
        collected_args = [initial_arg]
        if n == 1:
            return func(initial_arg)

        def cont(next_arg):
            collected_args.append(next_arg)
            if len(collected_args) == n:
                return func(*collected_args)
            return cont

        return cont
    return start


def uncurry(curry_func, n):
    if not isinstance(n, int):
        raise TypeError("Error! type(n)!=int")
    if n < 0:
        raise ValueError("Error! n<0")
    if n == 0:
        return curry_func

    def uncurried(*args):
        if len(args) != n:
            raise ValueError(f"Error! You give a count of arguments != n")
        res = curry_func
        for a in args:
            res = res(a)
        return res

    return uncurried

def sum3(x, y, z):
    return x + y + z

sum3_curry = curry(sum3, 3)
sum3_uncurry = uncurry(sum3_curry, 3)
print(sum3_curry(1)(2)(3))    # 6
print(sum3_uncurry(1, 2, 3))  # 6 
