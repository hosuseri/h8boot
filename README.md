# h8boot
## PREPARING
Install the binutils-h8300-hms and gcc-h8300-hms packages.

## BUILDING
1. Go to emb subdirectory and make. This completes libemb.a.
2. Go to the h8boot1 subdirectory and make. The h8boot1 executable is now complete.
3. Go to the h8boot2 subdirectory and make. You now have an h8boot2 executable.
4. Go to the h8tiny subdirectory and make. An h8boot shell script will be created.  Edit the "LINE" variable in h8boot to match the serial line you connect to your target board.
5. Place h8boot1, h8boot2, and h8boot in a directory in your PATH.

## USAGE
Flash the board by calling the h8boot shell script with the Motorola SREC file as an argument:
```
h8boot Monitor.mot
```
