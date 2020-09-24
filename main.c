#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

long long calc(char* cmd) {
	FILE* fp = popen(cmd, "r");
	if (fp == NULL) {
		return -1;
	}

	char space[64];
	while (fgets(space, sizeof(space), fp) != NULL) {
		//printf("%s", space);
	}

	pclose(fp);
	return atoll(space) / 1024;
}

int main() {
	// Samba calls this with pwd=root directory of the share.
	//
	// Our zfs layout looks like this:
	//   <pool>/<storage name>/<share name>
	// 
	// We want to have all shares belonging to the same <storage name> to report the same capacity.
	// Without this, adding files to one share keeps the total capacity of that share, and reduces
	// the total capacity of *all other shares*.
	chdir("..");

	long long used = calc("/usr/sbin/zfs get -o value -Hp used `pwd`");
	long long available = calc("/usr/sbin/zfs get -o value -Hp available `pwd`");
	long long total = used + available;
	printf("%lld %lld\n", total, available);
}
