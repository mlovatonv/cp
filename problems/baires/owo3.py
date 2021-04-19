def dist(s1, s2):
    if len(s1) > len(s2):
        s1, s2 = s2, s1

    distances = range(len(s1) + 1)
    for i2, c2 in enumerate(s2):
        distances_ = [i2+1]
        for i1, c1 in enumerate(s1):
            if c1 == c2:
                distances_.append(distances[i1])
            else:
                distances_.append(1 + min((distances[i1], distances[i1 + 1], distances_[-1])))
        distances = distances_
    return distances[-1]


def search(s1, s2, wordList, h):
    if s1 == s2:
        return h
    if not wordList:
        return 700
    ans = 700
    for s in wordList:
        d = dist(s1, s)
        if d == 1:
            wordList2 = [x for x in wordList if s != x]
            ans = min(ans, search(s, s2, wordList2, h + 1))
    return ans


def wordLadder(beginWord, endWord, wordList):
    ans = search(beginWord, endWord, wordList, 1)
    return ans if ans != 700 else 0

#print(wordLadder("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))

