def sum_cubes_from_to(a, b):
    sum = 0
    for num in range(a, b+1):
        num **= 3
        sum += num
    return sum

def next_N_sequence(n):
    seq = [n]
    for num in seq:
        if num > 1:
            if num % 2 == 0:
                new = int(num / 2)
            if num % 2 != 0:
                new = int(3 * num + 1)       
        if num == 1:
            break
        seq.append(new)
    return seq

def file_average(filename):
    with open(filename) as file:
        line_count = 0
        average = 0
        for line in file:
            average += float(line)
            line_count += 1
        average = average / line_count
    return average
        
if __name__ == '__main__':
    print('\nsum_cubes_from_to(1, 3) expect 36\n', sum_cubes_from_to(1, 3))
    print('\nsum_cubes_from_to(4, 8) expect 1260\n', sum_cubes_from_to(4, 8))
    print('\nnext_N_sequence(3), expect [3, 10, 5, 16, 8, 4, 2, 1]', next_N_sequence(3))
    print('\nnext_N_sequence(1), expect [1]', next_N_sequence(1))
    print("\nfile_average('oneNumPerLine_sample_1.txt') expect 5.0")
    print(file_average('oneNumPerLine_sample_1.txt'))