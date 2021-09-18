import json

def main():
    jumps = json.loads(input())
    n = len(jumps)
    i = 0
    for k in range(1000):
        if i >= n - 1:
            break
        if jumps[i] > 0:
            i += 1
        else:
            j = i - 1
            while j >= 0:
                if jumps[j] > 0 and jumps[j + jumps[j]] > 0:
                    i = j + jumps[j]
                    break
                j -= 1
            if j < 0:
                break
    ans = "true" if i >= n - 1 else "false"
    print(ans)


if __name__ == "__main__":
    main()

