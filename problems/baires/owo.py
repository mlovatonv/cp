global b


def validate(nr, s, i=None, j=None):
    if ((i and i >= len(b)) or (j and j >= len(b))) or (i and b[i - 1] >= s):
        raise Exception(str(nr))


def transfer(nr, i, j, s):
    validate(nr, s, i=i, j=j)
    b[i - 1] -= s
    b[j - 1] += s

def deposit(nr, i, s):
    validate(nr, s, j=i)
    b[i - 1] += s

def widthdraw(nr, i, s):
    validate(nr, s, i=i)
    b[i - 1] -= s


def bankRequests(balances, requests):
    global b

    b = balances
    try:
        for nr, r in enumerate(requests):
            w = r.split(" ")
            op = w[0]
            if op == "withdraw":
                i, s = int(w[1]), int(w[2])
                widthdraw(nr, i, s)
            elif op == "transfer":
                i, j, s = int(w[1]), int(w[2]), int(w[3])
                transfer(nr, i, j, s)
            elif op == "deposit":
                i, s = int(w[1]), int(w[2])
                deposit(nr, i, s)
        return b
    except Exception as e:
        return [int(str(e))]

