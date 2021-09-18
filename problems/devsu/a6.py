import json

def main():
    num = json.loads(input())
    ans = 0

    cnt = {}
    for i in num:
        if not cnt.get(i):
            cnt[i] = 0
        cnt[i] += 1

    keys = sorted(cnt.keys())

    mxacc = 0
    mxidx = 0
    for idx, k in enumerate(keys):
        acc = pow(cnt[i], 2)
        if acc > mxacc:
            mxacc = acc
            mxidx = idx

    del keys[mxidx]

    ans = mxacc
    # print(f"mxacc={mxacc}")

    for k in keys:
        n = len(num)
        acc = 0
        lacc = 0
        idx_to_del = []
        for i in range(n):
            if num[i] == k:
                idx_to_del.append(i)
                if i + 1 < n and num[i + 1] == k:
                    lacc += 1
                else:
                    acc += pow(lacc + 1, 2)
                    lacc = 0
        for i in sorted(idx_to_del, reverse=True):
            del num[i]
        ans += acc

    print(ans)

if __name__ == "__main__":
    main()
