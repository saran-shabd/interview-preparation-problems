
def solve(n):
    result = []

    # edge cases

    if 0 == n:
        return result

    result.append(1)
    if 1 == n:
        return result
    
    result.append(1)
    if (2 == n):
        return result
    
    # compute fibonacci numbers
    for i in range(2, n):
        result.append(result[i-1] + result[i-2])
    
    return result


def main():
    test_cases = int(input())
    for test in range(test_cases):
        n = int(input())
        result = solve(n)
        for i in range(len(result)):
            print(result[i], end=' ')
        print()


if __name__ == '__main__':
    main()
