from concurrent.futures import ProcessPoolExecutor
import time

def t():
    while(True):
        time.sleep(10)

with ProcessPoolExecutor(max_workers=2) as pool:
    fss = []
    fss.append(pool.submit(t))

    time.sleep(10)

    if(fss[0].cancle()):
        print("cacle true")
    else:
        print("cancle false")
        