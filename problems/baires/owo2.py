def findHarm(wA):
    idx = 0
    max_a = 0
    for i, a in enumerate(wA):
        if a > max_a:
            idx = i
            max_a = a
    return idx, max_a


def removeWarrior(wH, wA, idx):
    del wH[idx]
    del wA[idx]


def allianceVersusMonster(healthPoints, attackDamage):
    mH = healthPoints[0] # monsters
    mA = attackDamage[0]
    wH = healthPoints[1:] # warriors
    wA = attackDamage[1:]

    while mH > 0 and wH:
        wH2 = wH.copy()
        wA2 = wA.copy()
        while wA2:
            idx, max_a = findHarm(wA2) # find warrior with max attack
            wh = wH2[idx]
            wa = wA2[idx]
            if wh < mA:
                removeWarrior(wH2, wA2, idx)
            else:
                break
        if not wA2:
            return 0
        na = wh // mA # number of attacks
        mH -= na * wa
        if mH <= 0:
            break
        wh -= na * mA
        if wh <= 0:
            removeWarrior(wH, wA, idx)

    if mH > 0:
        return 0
    return len(wH)

print(allianceVersusMonster([11, 4, 4, 4],[1, 1, 1, 1]))

