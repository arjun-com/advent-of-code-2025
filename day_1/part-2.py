lines = []
with open("input.txt") as f:
    lines.extend(f.readlines())

pos = 50
zero_count = 0

for line in lines:
    line = line
    dirxn = +1 if line[0] == "R" else -1
    val = int(line[1:])

    full, part = divmod(val, 100)
    zero_count += full

    diff = -part if dirxn == -1 else part
    next_pos = pos + diff

    if pos != 0:
        if dirxn == -1 and next_pos <= 0:
            zero_count += 1
        elif dirxn == +1 and next_pos >= 100:
            zero_count += 1

    pos = next_pos % 100

print(zero_count)
