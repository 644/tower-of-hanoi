# Simpler Iterative Tower of Hanoi

This algorithm is so simple it makes larger stacks quite easy to do manually

[manual-hanoi.webm](https://user-images.githubusercontent.com/17060633/230754635-05195e06-ba4f-4d37-be75-b84bdff50171.webm)

---

It's quite similar to the already existing iterative solutions, but I've found it's not necessary to know which peg the disks are on, or which peg a disk will move to.

All that needs to be known is the direction (UP/DOWN), which alternates for each disk and is determined by the parity of the number of disks.
- For an even number of disks, the first only ever moves UP, the second DOWN, third UP, etc.
- For an odd number of disks, the first only ever moves DOWN, the second UP, third DOWN, etc.

Then we just do some calculations to get the number each disk will move on, and how many moves it will make in total.
- The first disk will move a total of `2^(n-1)` times, the second `2^(n-2)` times, etc. where `n` is the number of disks.
- The amount to increase its move position by (to then determine which move that disk will move on) is `2^(i+1)`, where `i` is the current disk number.

So for example with 4 disks labelled A - D:
```
A moves 2^3 times (8), and increases by 2^1 (2)
B moves 2^2 times (4), and increases by 2^2 (4)
C moves 2^1 times (2), and increases by 2^3 (8)
D moves 2^0 times (1), and increases by 2^4 (16)
```

It is pretty similar to binary counting and the Gray code solutions on [Wikipedia](https://en.wikipedia.org/wiki/Tower_of_Hanoi#Iterative_solution), but when solving it I chose not to do any research beyond knowing the rules of the game. If I had looked up the solutions beforehand, I probably wouldn't have come up with this one.
 
This probably isn't the best implementation for this algorithm, as it's pretty hacky, but at least it's extremely fast. From some simple benchmarks I've found it's ~3x faster than other iterative solutions, and ~10x faster than recursive ones.

Also only 110 lines of assembly gets generated with `-Ofast`, so have fun blowing up your CPU! (without arg parsing it's 58..)

# Install
Copy-paste into a shell with wget and gcc installed
``` sh
wget https://raw.githubusercontent.com/644/tower-of-hanoi/main/hanoi.c; gcc hanoi.c -ohanoi -Ofast
```

Then run with
``` sh
./hanoi 4
```

Outputs
```
A UP
B DOWN
A UP
C UP
A UP
B DOWN
A UP
D DOWN
A UP
B DOWN
A UP
C UP
A UP
B DOWN
A UP
```

I think the longest part here is the startup time from the executing shell
``` sh
time ./hanoi 20 >/dev/null

real	0.063
user	0.059
sys	0.003
cpu	99.23
```

---

[disks.webm](https://user-images.githubusercontent.com/17060633/230754345-37078ead-078e-40e8-8e7f-3e3c3e5fdd4e.webm)
