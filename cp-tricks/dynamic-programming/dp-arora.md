# Basic Elements of Dynamic Programming

(Complete Notes: Part 1, Part 2, Part 3)

## 1. What is Dynamic Programming?

Dynamic Programming (DP) is a problem-solving technique used to solve complex problems by breaking them into smaller subproblems, solving each subproblem once, and storing their results to avoid repeated work.

In simple words:
Dynamic Programming = Recursion + Storing results (memory)

DP is mainly used when a problem has:

1. Optimal substructure
2. Overlapping subproblems

---

## 2. Optimal Substructure

A problem has optimal substructure if the optimal solution of the problem can be constructed from optimal solutions of its subproblems.

Example: Fibonacci
The Fibonacci sequence is defined as:
F(n) = F(n − 1) + F(n − 2)

To find F(n), we need answers of smaller problems F(n − 1) and F(n − 2).
So the problem depends on its subproblems.

---

## 3. Overlapping Subproblems

A problem has overlapping subproblems if the same subproblem is solved multiple times.

Example: Recursive Fibonacci
When calculating F(5), the values F(3) and F(2) are computed many times.
This causes unnecessary repeated work.

Dynamic Programming avoids this by storing results.

---

## 4. Difference Between Divide & Conquer and DP

Divide & Conquer:

* Subproblems are independent
* No reuse of results
* Example: Merge Sort

Dynamic Programming:

* Subproblems overlap
* Results are reused
* Example: Fibonacci, Knapsack

---

## 5. What is a DP State?

A DP state is a set of parameters that uniquely defines a subproblem.

In DP, every subproblem must be representable using some parameters.
Those parameters together form the DP state.

---

### Example 1: Fibonacci

Problem: Find the nth Fibonacci number

DP State:
dp[n] = nth Fibonacci number

Only one parameter n is enough to uniquely define the subproblem.

---

### Example 2: Merge Sort (Conceptual)

Subproblem: Sort the subarray from index i to j

DP State:
dp[i][j] = sorted subarray from index i to j

Here two parameters (i, j) are needed.

---

### Example 3: Grid Path Problem

Problem: Minimum cost to reach cell (i, j)

DP State:
dp[i][j] = minimum cost to reach cell (i, j)

---

### Important Rule for DP State

* Use the minimum number of parameters
* The parameters must fully describe the subproblem
* Different parameter values must represent different subproblems

---

## 6. What is a Recurrence Relation?

A recurrence relation defines how one DP state depends on other DP states.

It is the mathematical relationship that connects the current state with smaller states.

---

### Example 1: Fibonacci Recurrence

dp[n] = dp[n − 1] + dp[n − 2]

---

### Example 2: Grid Minimum Path Sum

dp[i][j] = grid[i][j] + min(dp[i − 1][j], dp[i][j − 1])

---

### Example 3: Shortest Path in a DAG (Conceptual)

Let:
dp[u] = shortest path from node u to destination v

Recurrence:
dp[u] = min over all neighbors x of (cost(u, x) + dp[x])

This means:
From node u, try all outgoing edges and choose the minimum path.

---

## 7. Components of Any DP Solution

Every Dynamic Programming solution has three main parts:

1. DP State
2. Recurrence Relation
3. Base Case

---

### Base Case

Base cases are the smallest subproblems that can be solved directly without using recurrence.

Example (Fibonacci):
dp[0] = 0
dp[1] = 1

Without base cases, recursion will never stop.

---

## 8. Top-Down Dynamic Programming (Memoization)

Top-down DP starts from the original problem and recursively breaks it into smaller subproblems.

Each subproblem result is stored so that it is not recomputed.

---

### Top-Down Fibonacci Example

```
dp[n] = -1 initially

function fib(n):
    if n <= 1:
        return n
    if dp[n] is already computed:
        return dp[n]
    dp[n] = fib(n-1) + fib(n-2)
    return dp[n]
```

---

### Characteristics of Top-Down DP

* Uses recursion
* Easy to write and understand
* Naturally follows problem definition
* Uses extra stack space due to recursion

---

## 9. Bottom-Up Dynamic Programming (Tabulation)

Bottom-up DP starts by solving the smallest subproblems first and then builds up to the final answer.

No recursion is used.

---

### Bottom-Up Fibonacci Example

```
dp[0] = 0
dp[1] = 1
for i from 2 to n:
    dp[i] = dp[i-1] + dp[i-2]
```

---

### Characteristics of Bottom-Up DP

* Uses loops
* No recursion stack
* Usually faster in practice
* Requires correct order of computation

---

## 10. Top-Down vs Bottom-Up Comparison

Top-Down:

* Recursive
* Easier for beginners
* More intuitive
* Slightly slower due to recursion overhead

Bottom-Up:

* Iterative
* Harder at first
* More efficient
* Better control over memory

Both have the same asymptotic time complexity.

---

## 11. How to Visualize DP

To visualize DP, always think in this order:

1. What does one state represent?
2. From which previous states can it be reached?
3. In what order should states be computed?

---

### Example: Grid DP Visualization

Each cell dp[i][j] depends on:

* dp[i − 1][j] (top)
* dp[i][j − 1] (left)

So the DP table is filled row by row or column by column.

---

## 12. Time Complexity of DP

General rule:

Time Complexity =
(Number of DP states) × (Time to compute one state)

---

### Examples

Fibonacci:

* States: n
* Work per state: O(1)
* Total time: O(n)

Grid DP (n × m):

* States: n × m
* Time: O(n × m)

---

## 13. Space Complexity of DP

Space is used for:

1. DP table
2. Recursion stack (only in top-down)

---

### Example: Fibonacci

Space complexity:

* DP array: O(n)
* Recursion stack (top-down): O(n)

---

### Space Optimization

If only a few previous states are needed, space can be reduced.

Example:
Fibonacci needs only last two values.

Space optimized solution:
Space = O(1)

---

## 14. DP Thinking Strategy (Very Important)

When solving any DP problem, ask:

1. What is the subproblem?
2. What parameters define it? (DP State)
3. How does it depend on smaller subproblems? (Recurrence)
4. What are the base cases?
5. Should I use top-down or bottom-up?

---

## 15. Final Summary

* Dynamic Programming avoids repeated work
* DP State uniquely defines a subproblem
* Recurrence defines dependency between states
* Base cases stop recursion
* Top-down is recursive and intuitive
* Bottom-up is iterative and efficient
* Time = number of states × transition cost
* Space can often be optimized
