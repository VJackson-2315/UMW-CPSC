with open('pi_digits.txt', 'r') as in_file:
    mt = []
    for line in fh:
        mt.append(line[0:-1])
    pi_str = ''.join(mt)
    my_pi = float(pi_str)
    with open('new_pi.txt', 'w') as out_file:
        out_file.write('# pi info\n')
        out_file.write(in_file.readline())
        next_in = in_file.readline()
        new_line = next_in.count(' ') * '#' + next_in.lstrip()
        out_file.write(new_line)
        next_in = in_file.readline()
        new_line = next_in.count(' ') * '#' + next_in.lstrip()
        out_file.write(new_line)
        
        out_file.write('#\n')