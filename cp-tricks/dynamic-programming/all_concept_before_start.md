# **Dynamic Programming (DP) – Beginner-Friendly Notes**

## **1. Mindset Before Solving DP Problems**

Dynamic programming is all about solving **big problems by breaking them into smaller subproblems**, identifying overlaps, and reusing results. Here’s the step-by-step approach:

### **1.1 Divide and Conquer Mindset**

1. **Big problem → smaller subproblems**
   Example: Problem `P` → `P1, P2, P3`.

2. **Further divide subproblems if they are still big**
   `P1` → `A1, A2, A3`
   `P2` → `B1, B2, B3`

3. **Base case**: Stop dividing when the problem becomes trivial (easy to solve).

4. **Combine answers of subproblems** to get the answer for the bigger problem.
   Example with array sum:

   ```
   Array = [1, 2, 3, 4]
   Split into [1,2] and [3,4]
   [1,2] → 1+2 = 3
   [3,4] → 3+4 = 7
   Final sum = 3 + 7 = 10
   ```

---

### **1.2 Key Steps**

* **Identify smaller subproblems**
* **Define a relation (transition)** between smaller and bigger subproblems
* **Identify the base case(s)**
* **Combine answers** to solve the bigger problem

---

## **2. What is Dynamic Programming (DP)?**

DP is **Divide & Conquer + Memorization**:

* **Problem**: Some subproblems are calculated multiple times.
* **DP idea**: Calculate each subproblem **once**, store the result, and reuse it.

### **Example: Overlapping Subproblems**

```
Big problem P
 ├── P1 → A1, A2, A3
 ├── P2 → A2, A4, A5
 └── P3 → A1, A4, A5
```

* `A1` and `A2` repeat.
* Store results of `A1, A2` in memory. Next time you need them, **retrieve instead of recompute**.

---

### **2.1 Storing Results**

* **Array**: Use if subproblem indices are integers → O(1) access.

* **Map/Dictionary**: Use if subproblem indices are not integers (strings, tuples, etc.) → O(log n) for tree map or O(1) amortized for hash map.

* **Default value**: Indicate a subproblem hasn’t been solved yet.
  Example: `-1` or a number outside expected answer range.

---

## **3. Example: Fibonacci Numbers**

### **3.1 Problem**

* `F(1) = 1`, `F(2) = 1`
* `F(n) = F(n-1) + F(n-2)` for `n > 2`
* Goal: Find `F(n)` efficiently for `n` up to `10^5`.

---

### **3.2 Brute Force (Recursive)**

```cpp
int fib(int n) {
    if(n <= 2) return 1;           // Base case
    return fib(n-1) + fib(n-2);    // Divide & conquer
}
```

* Time complexity: **O(2^n)** → very slow
* Each subproblem recalculated multiple times

---

### **3.3 Recursive DP (Top-Down / Memoization)**

```cpp
int dp[MAX_N]; // initialize with -1
int fib(int n) {
    if(n <= 2) return 1;           // Base case
    if(dp[n] != -1) return dp[n];  // Already solved
    dp[n] = fib(n-1) + fib(n-2);   // Solve and store
    return dp[n];
}
```

* Top-down: Start from `n` → go to smaller subproblems
* Time complexity: **O(n)**
* Space complexity: **O(n)** + stack space for recursion

---

### **3.4 Iterative DP (Bottom-Up / Tabulation)**

```cpp
dp[1] = 1;
dp[2] = 1;
for(int i = 3; i <= n; i++)
    dp[i] = dp[i-1] + dp[i-2];
return dp[n];
```

* Bottom-up: Solve smaller problems first, then build up to `n`
* No recursion → no stack space
* Time complexity: **O(n)**
* Space complexity: **O(n)** (can optimize to O(1) using two variables)

---

### **3.5 Observations**

* Smaller subproblems must be solved **before** bigger ones.
* DP ensures overlapping subproblems are **calculated once**.
* Recursive = Top-down, Iterative = Bottom-up.
* Base cases are critical for recursion termination.

---

## **4. Terminology**

| Term                      | Meaning                                                    |
| ------------------------- | ---------------------------------------------------------- |
| **Subproblem**            | A smaller problem derived from the original problem        |
| **State**                 | Another name for a subproblem                              |
| **Transition / Relation** | Formula to combine smaller subproblems into bigger problem |
| **Base case**             | Smallest subproblem that can be solved trivially           |
| **Final problem**         | The biggest problem you initially want to solve            |

---

## **5. DP Problem-Solving Method (Standardized)**

1. **Identify the subproblem / state**
   Example: `DP[n] = nth Fibonacci number`

2. **Determine the parameters** that uniquely define each state
   Example: `n` is enough to identify `DP[n]`

3. **Define the transition** (relation between states)
   Example: `DP[n] = DP[n-1] + DP[n-2]`

4. **Identify the base case(s)**
   Example: `DP[1] = DP[2] = 1`

5. **Decide storage method** (array or map)

6. **Solve iteratively (bottom-up) or recursively (top-down)**

7. **Retrieve answers** from memory whenever needed

---

### **Key Tips**

* Always define your DP state clearly.
* Ensure each state has a **unique key**.
* Choose storage wisely: array if possible, map if not.
* Use a **default value** to check if a state is solved.
* Transition/recurrence is the heart of DP.
* Mindset: divide → solve subproblems → combine → reuse results.
