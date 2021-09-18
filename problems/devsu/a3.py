import json

def main():
    rooms = json.loads(input())
    n = len(rooms)
    ans = max(rooms)

    def dpfunc(s, f):
        if s >= n:
            return 0
        dp = [0] * n
        dp[s] = rooms[s]
        for i in range(s + 1, f):
            for j in range(i - 1):
                dp[i] = max(dp[i], dp[j] + rooms[i])
        return max(dp)

    ans = max([ans, dpfunc(0, n - 1), dpfunc(1, n), dpfunc(2, n)])
    print(ans)

if __name__ == "__main__":
    main()
