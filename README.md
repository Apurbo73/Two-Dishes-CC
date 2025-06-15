# Two-Dishes-CC:


---

### Problem Recap:

* Chef has `N` guests and wants to prepare **at least** `N` dishes in total.
* Two types of dishes:

  1. Dish type 1 = 1 fruit + 1 vegetable
  2. Dish type 2 = 1 vegetable + 1 fish
* Chef has:

  * `A` fruits
  * `B` vegetables
  * `C` fishes
* Question: Can Chef prepare at least `N` dishes total?

---

### Key points to note:

* Every dish requires exactly **one vegetable**.
* So, total dishes Chef can make can’t be more than `B` (vegetables).
* The sum of fruits + fishes doesn't limit directly, but they limit how many of each dish type Chef can make.

---

### What we want to find:

We want to check if there exists a way to split the `N` dishes into:

* `x` dishes of type 1 (fruit + vegetable)
* `y` dishes of type 2 (vegetable + fish)

such that:

* $x + y = N$
* $x \leq A$ (can’t use more fruits than available)
* $x \leq B$ (vegetables used for dish type 1)
* $y \leq C$ (can’t use more fishes than available)
* $y \leq B - x$ (vegetables left after using for dish type 1)

---

### How the code works:

```cpp
for (int x = 0; x <= N; ++x) {
    int y = N - x;  // Since total dishes = N
    if (x <= A && x <= B && y <= C && y <= B - x) {
        possible = true;
        break;
    }
}
```

* We loop through all possible numbers of type 1 dishes (`x` from 0 to `N`).
* For each `x`, calculate `y = N - x`.
* Check the conditions:

  * Do we have enough fruits? `x <= A`
  * Do we have enough vegetables for type 1 dishes? `x <= B`
  * Do we have enough fish for type 2 dishes? `y <= C`
  * Do we have enough vegetables left for type 2 dishes? `y <= B - x`
* If all these are true, it means we can make `N` dishes by using `x` type 1 and `y` type 2.
* We set `possible = true` and break out of the loop.

If after trying all values of `x`, no valid combination is found, `possible` remains `false`.

---

### Summary:

* The code tries all valid splits of `N` dishes into two types.
* It uses simple bounds checks to see if ingredients are sufficient.
* If any valid combination exists, print "YES", otherwise "NO".

---



 
The code tries all ways to split the total N dishes between the two types: type 1 (fruit + vegetable) and type 2 (vegetable + fish). For each split, it checks if Chef has enough fruits, vegetables, and fish to make those dishes.

If any split satisfies all ingredient limits (fruits, vegetables, fish), the code prints "YES"; otherwise, it prints "NO".
