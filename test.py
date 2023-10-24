#!/usr/bin/env python3
import random, string, subprocess, sys, time

INTERVAL = 0.5
DEFAULT_MIN_LENGTH = 10
DEFAULT_MAX_LENGTH = 50
message = "`~(*123!@#$%^&*(_+-=][}{';:.></|\\?) Ž (╯°□°)╯︵ ┻━┻"


if len(sys.argv) == 5:
    min_len = int(sys.argv[3])
    max_len = int(sys.argv[4])
else:
    min_len = DEFAULT_MIN_LENGTH
    max_len = DEFAULT_MAX_LENGTH
if (len(sys.argv) < 3):
	print("Usage: python3 test.py <number of requests> <server address> <?min length> <?max length>")
	exit(1)
for _ in range(int(sys.argv[1])):
	random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(min_len/2, max_len/2))) + ''.join(random.choices(message, k=random.randint(min_len/2, max_len/2)))
	subprocess.call(["./client", sys.argv[2], random_string])
	time.sleep(INTERVAL)
