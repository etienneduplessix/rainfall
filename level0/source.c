#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }
    int val = atoi(argv[1]);
    if (val == 423) {
        char *shell = strdup("/bin/dash"); 
        char *args[] = {shell, NULL};

        gid_t gid = getegid();
        uid_t uid = geteuid();

        setresgid(gid, gid, gid);
        setresuid(uid, uid, uid);

        execv("/bin/dash", args);
    } else {
        fwrite("No !\n", 1, 5, stderr);
    }

    return 0;
}