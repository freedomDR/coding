import random
import heapq
import time

def generateArr():
    with open("large_sort.txt", "w") as f:
        for i in range(1000000):
            x = random.randint(1, 10000000)
            res = f.write(str(x)+"\n")

def sortAndSave(file_name, arr):
    tmp_arr = sorted(arr)
    with open(file_name, "w") as ff:
        tmp_arr_str = [str(x) for x in tmp_arr]
        ff.write("\n".join(tmp_arr_str))
    

def splitFile():
    max_rows = 1*1024*1024*1024//8
    file_flag = 0
    tmp_arr = []
    with open("large_sort.txt", "r") as f:
        for line in f.readlines():
            line = line.strip()
            if (line == ""): continue
            x = int(line)
            tmp_arr.append(x)
            if (len(tmp_arr) == max_rows):
                sortAndSave(f"tmp_sort_{file_flag}.txt", tmp_arr)
                file_flag += 1
                tmp_arr.clear()
        if (len(tmp_arr) > 0):
            sortAndSave(f"tmp_sort_{file_flag}.txt", tmp_arr)
            file_flag += 1
    return file_flag

def merge(file_flag):
    file_map = {}
    pq = []
    heapq.heapify(pq)
    for i in range(file_flag):
        file_map[i] = open(f"tmp_sort_{i}.txt", "r")
        x = int(file_map[i].readline().strip())
        heapq.heappush(pq, [x, i])
    
    pre = -1

    cnt = 0
    sort_file = open("large_sort_result.txt", "w")
    while (len(file_map) > 0):
        x, pos = heapq.heappop(pq)
        sort_file.write(f"{x}\n")
        cnt += 1
        assert(x>=pre)
        pre = x 
        if (pos in file_map.keys()):
            line = file_map[pos].readline()
            if (line == ""):
                file_map[pos].close()
                file_map.pop(pos)
            else:
                nxt = int(line.strip())
                heapq.heappush(pq, [nxt, pos])
    sort_file.close()
    print(cnt)

if (__name__ == "__main__"):
    generateArr()
    file_flag = splitFile()
    merge(file_flag)
            