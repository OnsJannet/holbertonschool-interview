#!/usr/bin/python3

'''
Reads stdin line by line and computes metrics
'''
import sys

if __name__ == "__main__":

    status_list = {"200": 0, "301": 0, "400": 0, "401": 0,
                   "403": 0, "404": 0, "405": 0, "500": 0}

    file_size = 0

    def print_status():
        """Prints the accumulated logs"""
        print("File size: {}".format(file_size))
        for status in sorted(status_list.keys()):
            if status_list[status]:
                print("{}: {}".format(status, status_list[status]))

    if __name__ == "__main__":
        count = 0
        try:
            for line in sys.stdin:
                try:
                    data = line.split()
                    file_size += int(data[-1])
                    if data[-2] in status_list:
                        status_list[data[-2]] += 1
                except BaseException:
                    pass
                count += 1
                if count == 9:
                    print_status()
                    count = -1
                count += 1
        except KeyboardInterrupt:
            print_status()
            raise
        else:
            print_status()
