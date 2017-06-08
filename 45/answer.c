/*
 * Jump Game II 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 *
 * Note:
 * You can assume that you can always reach the last index.
 */
#include <stdio.h>


int jump(int* nums, int numsSize) {
  if (numsSize <= 1) {
    return 0;
  }

  int hops = 1;
  int cur = 0;
  int cur_jump = nums[cur];

  /* This is an improved BFS by noting that at each level in the tree the 
   * maximum jump that can be done is always the winner. (If a jump can be done
   * to index 20, from a tree node, jump can be made to any of the indexes < 20
   * from this node.) So the best node at this level is the node from which
   * highest jump can be performed
   */
  while ((cur+cur_jump) < numsSize-1) {
    int next_jump=cur_jump;
    int next=cur;
    for (int i = cur+1; i <= (cur+cur_jump); i++) {
      if ((nums[i] + i) > (next+next_jump)) {
        next = i;
        next_jump = nums[i];
      }
    }
    hops++;
    cur = next;
    cur_jump = next_jump;
  }

  return hops;
}

#define NELMS(x) sizeof(x)/sizeof(x[0])

void main(void) {
  int a[] = {1,2,3}; // 2
  //int a[] = {2,3,1,1,4}; // 2
  //int a[] = {1,2}; // 1 
  //int a[] = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3}; //2

  printf("%d\n", jump(a, NELMS(a)));
}
