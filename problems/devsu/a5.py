import json

def main():
    s = input() # source
    t = input() # target
    sn = len(s)
    tn = len(t)

    ans = 0

    def search(si, ti):
        if ti == tn:
            nonlocal ans
            ans += 1
            return

        for i in range(si, sn):
            if s[i] == t[ti]:
                search(i + 1, ti + 1)

    search(0, 0)
    print(ans)

if __name__ == "__main__":
    main()
