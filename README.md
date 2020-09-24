# dfree

Given a ZFS storage layout as

```
pool1
  - storage1
    - share1
    - share2
pool2
  - storage2
    - share3
    - share4
```

This file will print the total + available space on each *storage* dataset
when invoked by samba for each *share* dataset, so that all shares belonging
to the same storage node will display the same available and total space.

Actual quotas of share folders are ignored (since I'm not using them).

This still reduces the total space listed when files outside pool/storage are
updated (such as adding new files to rpool/ROOT), but accurately reflects
the totals available to you at time of querying.

## Build

```
gcc main.c && mv a.out /usr/local/bin/dfree
```

## Samba config

In `/etc/samba/smb.conf`:

```
[global]
  dfree command = /usr/local/bin/dfree
```
