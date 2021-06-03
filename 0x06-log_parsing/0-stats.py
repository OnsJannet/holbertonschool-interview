#!/usr/bin/python3

""" reads stdin line by line and computes metric"""

if __name__ == '__main__':

    def printer(file_size, status):

        '''Print logs'''

        print("File size: {:d}".format(file_size))
        for i in sorted(status.keys()):
            if status[i] != 0:
                print("{}: {}".format(i, status[i]))

    file_size = 0
    status = {"200": 0, "301": 0, "400": 0, "401": 0,
              "403": 0, "404": 0, "405": 0, "500": 0}

    counter = 0
    try:
        with open(0) as f:
            for line in f:
                counter += 1
                data = line.split()

                try:
                    file_size += int(data[-1])
                except Exception:
                    pass

                try:
                    st = data[-2]
                    if st in status:
                        status[st] += 1

                except Exception:
                    pass
                if counter % 10 == 0:
                    printer(file_size, status)
            printer(file_size, status)
    except KeyboardInterrupt:
        printer(file_size, status)
        raise
