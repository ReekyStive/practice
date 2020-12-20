n = int(input())
files = []


def touch(name):
    for item in files:
        if item == name:
            return
    files.append(name)


def rm(name):
    try:
        files.remove(name)
    except ValueError:
        pass


def rename(old, new):
    for item in files:
        if item == new:
            return

    for i in range(len(files)):
        if files[i] == old:
            files[i] = new
            return


def ls():
    for item in files:
        print(item)


for t in range(n):
    cmd = input().strip().split(' ')

    while '' in cmd:
        cmd.remove('')

    if cmd[0] == 'touch':
        touch(cmd[1].strip())
    elif cmd[0] == 'rm':
        rm(cmd[1].strip())
    elif cmd[0] == 'rename':
        rename(cmd[1].strip(), cmd[2].strip())
    elif cmd[0] == 'ls':
        ls()
