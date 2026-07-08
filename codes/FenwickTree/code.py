from typing import List

class Fenwick:
    def __init__(self, n_or_a):
        if isinstance(n_or_a, int):
            self.n = n_or_a
            self.bit = [0] * (self.n + 1)
        else:
            a = n_or_a
            self.n = len(a) - 1
            self.bit = a[:]
            for i in range(1, self.n + 1):
                j = i + (i & -i)
                if j <= self.n:
                    self.bit[j] += self.bit[i]

    def add(self, i: int, val: int) -> None:
        while i <= self.n:
            self.bit[i] += val
            i += i & -i

    def sum(self, i: int) -> int:
        res = 0
        while i > 0:
            res += self.bit[i]
            i -= i & -i
        return res

    def range_sum(self, l: int, r: int) -> int:
        return self.sum(r) - self.sum(l - 1)


class RangeFenwickRQ:
    def __init__(self, n: int):
        self.n = n
        self.bit1 = Fenwick(n)
        self.bit2 = Fenwick(n)

    def _add(self, idx: int, val: int) -> None:
        self.bit1.add(idx, val)
        self.bit2.add(idx, val * (idx - 1))

    def range_add(self, l: int, r: int, val: int) -> None:
        self._add(l, val)
        self._add(r + 1, -val)

    def prefix_sum(self, idx: int) -> int:
        return self.bit1.sum(idx) * idx - self.bit2.sum(idx)

    def range_sum(self, l: int, r: int) -> int:
        return self.prefix_sum(r) - self.prefix_sum(l - 1)


class RangeFenwickPQ:
    def __init__(self, n: int):
        self.n = n
        self.bit = [0] * (n + 1)

    def add(self, idx: int, val: int) -> None:
        while idx <= self.n:
            self.bit[idx] += val
            idx += idx & -idx

    def range_add(self, l: int, r: int, val: int) -> None:
        self.add(l, val)
        self.add(r + 1, -val)

    def get(self, idx: int) -> int:
        res = 0
        while idx > 0:
            res += self.bit[idx]
            idx -= idx & -idx
        return res


class FenwickMin:
    INF = 10**9

    def __init__(self, n: int):
        self.n = n
        self.bit = [self.INF] * n

    def update(self, i: int, val: int) -> None:
        while i < self.n:
            if val < self.bit[i]:
                self.bit[i] = val
            i = i | (i + 1)

    def query(self, r: int) -> int:
        ans = self.INF
        while r >= 0:
            if self.bit[r] < ans:
                ans = self.bit[r]
            r = (r & (r + 1)) - 1
        return ans


class FenwickMax:
    NEG_INF = -10**9

    def __init__(self, n: int):
        self.n = n
        self.bit = [self.NEG_INF] * n

    def update(self, i: int, val: int) -> None:
        while i < self.n:
            if val > self.bit[i]:
                self.bit[i] = val
            i = i | (i + 1)

    def query(self, r: int) -> int:
        ans = self.NEG_INF
        while r >= 0:
            if self.bit[r] > ans:
                ans = self.bit[r]
            r = (r & (r + 1)) - 1
        return ans


class Fenwick2D:
    def __init__(self, n: int, m: int):
        self.n = n
        self.m = m
        self.bit = [[0] * (m + 1) for _ in range(n + 1)]

    def add(self, x: int, y: int, val: int) -> None:
        i = x
        while i <= self.n:
            j = y
            while j <= self.m:
                self.bit[i][j] += val
                j += j & -j
            i += i & -i

    def sum(self, x: int, y: int) -> int:
        res = 0
        i = x
        while i > 0:
            j = y
            while j > 0:
                res += self.bit[i][j]
                j -= j & -j
            i -= i & -i
        return res

    def range_sum(self, x1: int, y1: int, x2: int, y2: int) -> int:
        return self.sum(x2, y2) - self.sum(x1 - 1, y2) - self.sum(x2, y1 - 1) + self.sum(x1 - 1, y1 - 1)

