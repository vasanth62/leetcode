/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <stdio.h>
#include <stdlib.b>

bool isMatch(char *s, char *p) {
  if (!s || !p)
    return false;
  while (*s && *p) {

    if (*p == '.')
  }

  if (*s) {
    if (!*p || *p != '*') {
      return false;
    }
  }

  while (*p) {
    if (*p != '*') {
      return false;
    }
    p++;
  }
  return true;
}


int main (void) {
  if (isMatch("aa","a") != false) {
    printf("%d fail\n", __LINE__);
  }
  if (isMatch("aa", "aa") != true) {
    printf("%d fail\n", __LINE__);
  }
  if (isMatch("aaa", "aa") != false) {
    printf("%d fail\n", __LINE__);
  }
  if (isMatch("aa", "a*") != true) {
    printf("%d fail\n", __LINE__);
  }
  if (isMatch("aa", ".*") != true) {
    printf("%d fail\n", __LINE__);
  }
  if (isMatch("ab", ".*") != true) {
    printf("%d fail\n", __LINE__);
  }
  if (isMatch("aab", "c*a*b") != true) {
    printf("%d fail\n", __LINE__);
  }
  return 0;
}
