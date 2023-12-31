import subprocess
import argparse
import time
from subprocess import Popen, PIPE, STDOUT

class TERMINAL_COLORS:
        PURPLE    = '\033[95m'
        OKBLUE    = '\033[94m'
        OKCYAN    = '\033[96m'
        OKGREEN   = '\033[92m'
        WARNING   = '\033[93m'
        ERROR     = '\033[91m'
        DEFAULT   = '\033[0m'
        BOLD      = '\033[1m'
        UNDERLINE = '\033[4m'


data_files_names = [f"../tests/e2e/data/{i}.dat" for i in range(1, 16)]

def check_output_data(n_test, stdout_data, correct_output, exec_time):
        try:
                if stdout_data == correct_output:
                        print(TERMINAL_COLORS.OKGREEN                    + \
                                f"Test {n_test:3} Passed. "              + \
                                f"File {data_files_names[n_test]} "      + \
                                f"Execution time: {exec_time:.03f} sec"  + \
                        TERMINAL_COLORS.DEFAULT
                        )
                else:
                        print(TERMINAL_COLORS.ERROR                   + \
                                f"Test {n_test} NOT Passed. "         + \
                                f"File {data_files_names[n_test]}\n"  + \
                                f"Output={stdout_data}\n"             + \
                                f"\nRight={correct_output}\n"           + \
                        TERMINAL_COLORS.DEFAULT
                        )
        except:
                print(TERMINAL_COLORS.WARNING                                 + \
                        f"Test {n_test} has fallen. Output of program is:\n'" + \
                        stdout_data + "'"                                     + \
                      TERMINAL_COLORS.DEFAULT
                      )


def get_correct_output (n_triangles, data):
        correct_output = data[n_triangles*3*3:]
        return correct_output


def parse_data_file (file_name):
        with open(file_name) as file:
                n_triangles = int(next(file))

                coords = []
                n_line2scan = n_triangles*3

                for line in file:
                        for x in line.split():
                                coords.append(float(x))

                correct_output = get_correct_output(n_triangles, coords)
                coords = coords[:n_triangles*3*3]
                coords.insert(0, n_triangles)

                return coords, correct_output


def run_e2e_test(app2run, input_data):
        pipe = Popen([app2run], stdout=PIPE, stdin=PIPE)
        
        data_str = str()
        for data in input_data:
                data_str += str(data) + " "

        start_time = time.time()
        stdout_data = pipe.communicate(input=bytes(data_str, "UTF-8"))
        exec_time = time.time() - start_time

        return stdout_data[0].decode(), exec_time
        

def run_e2e_tests(app_name):
        for (n_test, file_name) in zip(range(len(data_files_names)), data_files_names):
                data, correct_output = parse_data_file(file_name)

                output_data, exec_time = run_e2e_test(app_name, data)
                output_data = output_data[:len(output_data) - 1]
                
                correct_str = '\n'.join(str(int(elem)) for elem in correct_output)
                check_output_data(n_test, output_data, correct_str, exec_time)


if __name__ == "__main__":
        run_e2e_tests("./triangles")