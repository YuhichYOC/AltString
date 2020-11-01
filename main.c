#include "AltString.h"

void testRun01() {
    char value[] = "abcde";
    AltString * s = AltString_init(value);
    if (NULL == s) {
        return;
    }
    printf("testRun01 : %s\n", s->get(s));
    s->dispose(s);
}

void testRun02() {
    char value[] = "abcdef";
    AltString * s = AltString_init(value);
    if (NULL == s) {
        return;
    }
    printf("testRun02 : length = %d\n", s->getLength(s));
    printf("testRun02 : indexOf \'c\' = %d\n", s->indexOf(s, 'c'));
    s->dispose(s);
}

void testRun03() {
    char value[] = "abcde";
    AltString * s = AltString_init(value);
    if (NULL == s) {
        return;
    }
    char * sub = s->subString(s, 1, 3);
    printf("testRun03 : subString = %s\n", sub);
    printf("testRun03 : value = %s\n", s->get(s));
    free(sub);
    s->dispose(s);
}

void testRun04() {
    char value[] = "abcde";
    AltString * s = AltString_init(value);
    if (NULL == s) {
        return;
    }
    char * cut = s->cut(s, 'c');
    printf("testRun04 : cut = %s\n", cut);
    printf("testRun04 : value = %s\n", s->get(s));
    printf("testRun04 : length = %d\n", s->getLength(s));
    free(cut);
    s->dispose(s);
}

int main() {
    testRun01();
    testRun02();
    testRun03();
    testRun04();
    return 0;
}
