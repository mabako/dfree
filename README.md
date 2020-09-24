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

