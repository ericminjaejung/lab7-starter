#include "jstr.c"


// This one has a subtle bug. There isn't really a one-line fix for this,
// but can you use valgrind to figure out the issue?
String substring2(String s, int start, int end) {
    assert(start >= 0);
    assert(end <= s.length);
    assert(start <= end);
    
    // Make a copy of s.contents for us to substringify
    int new_length = end - start;
    char* substring = malloc(new_length + 1);

    int i;
    for (i = 0; i < new_length; ++i) {
        substring[i] = s.contents[start + i];
    }

    substring[new_length] = '\0';
    
    String r = { new_length, substring};
    return r;
}

int main() {
    
    String abcdef2 = new_String("abcdef");
    String def2 = substring2(abcdef2, 3, 6);
    printf("%s\n", def2.contents);
    free(def2.contents);
    free(abcdef2.contents);
}
