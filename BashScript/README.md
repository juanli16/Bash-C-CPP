# Bash Sample Scripts and Useful commands

**Cheatsheet**
To run commands sequentially
```Bash
A; B	#Run A then B, regardless of success of A
A && B	#Run B if A succeeded
A || B  #Run B if A failed
A &	#Run A in background
```
To run a job remotely through ssh in background
and does not kill the job when logout
```Bash
nohup ./script &
```


