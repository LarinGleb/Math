from itertools import count
import os

files = os.listdir(path=".")
count_strings = 0
import os
import os.path

for dirpath, dirnames, filenames in os.walk(".."):
    for filename in [f for f in filenames if f.endswith(".cpp") or f.endswith(".c") or f.endswith(".h") or f.endswith(".txt")]:
        with open(os.path.join(dirpath, filename), "r") as file:
            if("build" not in dirpath):
                read_file = file.readlines()
                print(f"-Dir: {dirpath}, file: {filename}, count: {len(read_file)}")
                count_strings += len(read_file)
print("Количество строк в проекте:", count_strings)