#include <r_util.h>
#include "minunit.h"

int tests_run = 0;
char* buf;

char* test_r_base64_decode(void) {
  char* hello = (char*)r_base64_decode_dyn ("aGVsbG8=", 0);
  sprintf(buf, "error, b64decode(hello) failed : %s", hello);
  mu_assert(buf, strcmp(hello, "hello") == 0);
  return NULL;
}

char* test_r_base64_encode(void) {
  char* hello = (char*) r_base64_encode_dyn("hello", 0);
  sprintf(buf, "error, b64encode(hello) != %s", hello);
  mu_assert(buf, strcmp(hello, "aGVsbG8=") == 0);
  return NULL;
}

char* all_tests() {
  mu_run_test(test_r_base64_decode);
  mu_run_test(test_r_base64_encode);
  return NULL;
}

int main(int argc, char **argv) {
  buf = malloc(1024);
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}