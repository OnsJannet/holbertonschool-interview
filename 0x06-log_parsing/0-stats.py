#!/usr/bin/python3

'''
Reads stdin line by line and computes metrics
'''
import sys

if __name__ == "__main__":

    def print_status(file_size, status_list):
        """Prints the accumulated logs"""
        print("File size: {}".format(file_size))
        for status in sorted(status_list.keys()):
            if status_list[status]:
                    print("{}: {}".format(status, status_list[status]))


    status_list = {"200": 0, "301": 0, "400": 0, "401": 0,
                   "403": 0, "404": 0, "405": 0, "500": 0}
    file_size = 0
    count = 0

    try:
        for line in sys.stdin:
            count += 1
            data = line.split()

            try:
                file_size += int(data[-1])
            except:
                pass

            try:
                item = data[-2]
                if item in status_list:
                    status_list[item] +=1
            except:
                pass

            if count % 10 == 0:
                print_status(file_size, status_list)
            print_status(file_size, status_list)
    except KeyboardInterrupt:
        print_status(file_size, status_list)
        raise

