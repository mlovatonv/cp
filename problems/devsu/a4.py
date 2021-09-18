import json

def sae(l):
    nl = []
    for idx, i in enumerate(l):
        nl.append((i, idx))
    return sorted(nl, reverse=True)



def main():
    dam = json.loads(input())
    vic2 = json.loads(input())
    vic = sae(vic2)
    c = int(input())
    n = len(dam)

    def momfunc(idxs):
        mom = sum(dam[x] for x in idxs) % (1e9 + 7)
        mom *= min(vic2[x] for x in idxs) % (1e9 + 7)
        mom %= (1e9 + 7)
        return mom

    ans = 0
    for i in range(n - c):
        ans = max(ans, momfunc([i for _, i in vic[i:i + c]]))

    print(int(ans))


if __name__ == "__main__":
    main()
