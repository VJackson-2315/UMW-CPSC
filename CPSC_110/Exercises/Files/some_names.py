def batch_unames(filename):
    with open(filename) as in_file:
        with open('batch_unames.txt', 'w') as out_file:
            for line in in_file:
                names = line.split()
                first_in = names[0][0]
                last_name = names[-1][0:7]
                uname = (first_in + last_name)
                out_string = str(uname)
                out_string = out_string.lower() + "\n"
                out_file.write(out_string)

if __name__ == "__main__":
    batch_unames('presidents.txt')