import random
import logging

logging.basicConfig(format="%(asctime)s %(lineno)s %(levelname)s %(message)s",level=logging.INFO)

if(__name__ == '__main__'):
    arr = []
    for i in range(100):
        arr.append(random.randint(1,1000))
    f = open("./in.txt", "a")
    f.write("{}\n".format(len(arr)))
    for v in arr:
        f.write("{}\n".format(v))
        for i in range(v):
            a = random.randint(1, 100)
            b = random.randint(1, 100)
            c = random.randint(1, a+b)
            f.write("{} {} {}\n".format(a, b, c))
    logging.info(len(arr))
    f.close()

    