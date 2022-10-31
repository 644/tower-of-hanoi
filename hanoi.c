/* Author: 644 - https://github.com/644
 * Title: Simpler Iterative Solution to the Tower of Hanoi Problem
 * License: MIT
 * 
 * Notes:
 * It's quite similar to the already existing iterative solutions, but I've found it's not necessary to know which peg the disks are on, or which peg a disk will move to.
 * All that needs to be known is the direction (UP/DOWN), which alternates for each disk and is determined by the parity of the number of disks.
 * For an even number, the first disk moves UP, the second DOWN, third UP, etc.
 * For an odd number, the first disk moves DOWN, the second UP, third DOWN, etc.
 *
 * Then we just do some calculations to get the number each disk will move on, and how many moves it will make in total.
 * For the first disk it will move 2^(n-1) times, and the second 2^(n-2) times, etc. where n is the number of disks.
 * For the amount to increase its move position by, it's just 2^(i+1) where i is the current disk number.
 *
 * So for example with 4 disks labelled A - D:
 * 		A moves 2^3 times, and increases by 2^1.
 * 		B moves 2^2 times, and increases by 2^2.
 * 		C moves 2^1 times, and increases by 2^3.
 * 		D moves 2^0 times, and increases by 2^4.
 *
 * It is pretty similar to binary counting and the Gray code solutions, but when solving it I chose not to do any research beyond knowing the rules of the game. If I had looked up the solutions beforehand, I probably wouldn't have come up with this one.
 * 
 * Also this probably isn't the best implementation for this algorithm, as it's extremely hacky, but at least it's fast. And only 58 lines of assembly gets generated with -Ofast, so have fun blowing up your CPU!
 */

#include <stdio.h>

static const int ring_count = 4;
static const int total_moves = (1 << ring_count) - 1;
static const int is_odd = ring_count & 1;

void solve_hanoi(){
    int move_order[total_moves];

    for(int i=0; i<ring_count; i++){
        int c_ring_pos = 1 << i;
        int inc_amount = 1 << (i+1);
        move_order[c_ring_pos-1] = 'A'+i;
        for(int j=0; j<(1 << ring_count-(i+1))-1; j++){
            c_ring_pos += inc_amount;
            move_order[c_ring_pos-1] = 'A'+i;
        }
    }

    for(int i=0; i<total_moves; i++){
        if(move_order[i]+is_odd & 1){
            printf("%c UP\n", move_order[i]);
        } else {
            printf("%c DOWN\n", move_order[i]);
        }
    }
}

int main(){
    solve_hanoi();
    return 0;
}
