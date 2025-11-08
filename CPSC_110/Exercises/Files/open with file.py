with open('pi_digits.txt', 'r') as fh:
    mt = []
    fh.readline()
    for line in fh:
        mt.append(line[0:-1])
    pi_str = ''.join(mt)
    my_pit = float(pi_str)
    print(len(pi_str))
    print(my_pi)