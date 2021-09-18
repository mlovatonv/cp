import json

inf = 500

def main():
    bars = json.loads(input())
    n = len(bars)
    ans = 0
    for i in range(n):
        for j in range(i + 1, n):
            h = min(bars[i], bars[j])
            w = (j - i) * 3;
            # print(f"i={i} j={j} h={h} w={w}")
            ans = max(ans, h * w)
    print(ans)


if __name__ == "__main__":
    main()
