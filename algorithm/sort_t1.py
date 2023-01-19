import logging
import random

logging.basicConfig(format="%(threadName)s %(asctime)s %(levelname)s line %(lineno)s : %(message)s", datefmt="%Y-%m-%d %H:%M:%S", level=logging.INFO)

logger = logging.getLogger(__name__)

arr = random.sample(range(15), 10)
arr.extend(random.sample(range(15), 10))
logger.info(f"arr: {arr}")

def quick_sort(l, r):
    if(l>=r):
        return
    ll, rr = l, r
    flag = arr[(l+r)//2]
    arr[(l+r)//2] = arr[l]
    while(l<r):
        while(l<r and arr[r] >= flag):
            r -= 1
        if(l<r):
            arr[l] = arr[r]
        while(l<r and arr[l] < flag):
            l += 1
        if(l<r):
            arr[r] = arr[l]
    assert(l == r)
    arr[l] = flag
    quick_sort(ll, l-1)
    quick_sort(l+1, rr)

def merge_sort(l, r):
    global arr
    if(l>=r):
        return
    ll, rr = l, r
    mid = (l+r)//2
    merge_sort(l, mid)
    merge_sort(mid+1, r)
    new_arr = []
    p1, p2 = l, mid+1
    while(p1 <= mid and p2 <= r):
        if(arr[p1] < arr[p2]):
            new_arr.append(arr[p1])
            p1 += 1
        else:
            new_arr.append(arr[p2])
            p2 += 1
    while(p1 <= mid):
        new_arr.append(arr[p1])
        p1 += 1
    while(p2 <= r):
        new_arr.append(arr[p2])
        p2 += 1
    arr[ll:rr+1] = new_arr

def f(l, r):
    parent, son = l, l*2+1
    while(son <= r):
        if(son+1 <= r and arr[son+1] > arr[son]):
            son += 1
        if(arr[parent] >= arr[son]):
            return
        else:
            arr[parent], arr[son] = arr[son], arr[parent]
            parent = son
            son = parent * 2 + 1

def heap_sort():
    for i in range((len(arr)-1-1)//2, -1, -1):
        f(i, len(arr)-1)
    for i in range(len(arr)-1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        f(0, i-1)


# quick_sort(0, len(arr)-1)
# merge_sort(0, len(arr)-1)
heap_sort()

logger.info(f"arr: {arr}")
