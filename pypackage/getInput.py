import sys
import termios


def getchar():
    old = termios.tcgetattr(sys.stdin)
    cbreak = old.copy()
    cbreak[3] &= ~(termios.ECHO | termios.ICANON)
    cbreak[6][termios.VMIN] = 1
    cbreak[6][termios.VTIME] = 0
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, cbreak)
    char = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old)
    return char


while True:
    c = getchar()
    print("Key is %s" % c)
    if c == 'x':
        break;
