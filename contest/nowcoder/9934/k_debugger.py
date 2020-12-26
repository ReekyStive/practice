import subprocess
import random


def compare(a):
    para_str = '5' + '\n' + a + '\n'

    output_1 = subprocess.run(
        r'k.exe', input=para_str.encode(), capture_output=True)
    output_2 = subprocess.run(
        r'k_miao.exe', input=para_str.encode(), capture_output=True)

    output_1 = output_1.stdout.decode().strip()
    output_2 = output_2.stdout.decode().strip()

    print('Output 1:')
    print(output_1)
    print('Output 2:')
    print(output_2)

    if output_1 != output_2:
        input()


if __name__ == '__main__':
    for t in range(1000):
        rand_1 = []
        rand_2 = []
        for i in range(5):
            rand_1.append(int(random.random() * 10))
            rand_2.append(int(random.random() * 10))

        in_str = ''
        for i in range(5):
            in_str += str(rand_1[i]) + ' '
        in_str += '\n'
        for i in range(5):
            in_str += str(rand_2[i]) + ' '

        print('Case ' + str(t + 1) + ':')
        print('Input:')
        print(in_str)
        compare(in_str)
        print()
