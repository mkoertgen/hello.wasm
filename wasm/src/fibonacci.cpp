#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
int fibonacci(int n) {
  if (n == 0 || n == 1)
    return n;
  else
    return (fibonacci(n-1) + fibonacci(n-2));
}