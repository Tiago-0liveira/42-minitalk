import random, string, subprocess, sys, time

bytes = 0
for _ in range(int(sys.argv[1])):
	random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(*map(int, sys.argv[3:5]))))
	subprocess.call(["./client", sys.argv[2], random_string])
	bytes += len(random_string) * 8
	print(f"bytes: {bytes}")
	time.sleep(0.1)
