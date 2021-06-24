import subprocess


def compare(a, b, n):
    para_str = '1' + '\n' + str(a) + ' ' + str(b) + ' ' + str(n) + '\n'
    output_1 = subprocess.run(
        r'b.exe', input=para_str.encode(), capture_output=True)
    output_2 = subprocess.run(
        r'b_miao.exe', input=para_str.encode(), capture_output=True)

    output_1 = output_1.stdout.decode().strip()
    output_2 = output_2.stdout.decode().strip()

    if output_1 != output_2:
        print('Input: ' + str(a) + ' ' + str(b) + ' ' + str(n))
        print('Out 1: ' + output_1)
        print('Out 2: ' + output_2)
        input()


if __name__ == '__main__':
    for a in range(-100, 101):
        for b in range(-100, 101):
            for n in range(1, 31):
                compare(a, b, n)
