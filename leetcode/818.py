import logging
from collections import defaultdict
import heapq
import math

logging.basicConfig(format='%(threadName)s %(asctime)s %(levelname)s line %(lineno)s : %(message)s',datefmt='%Y-%m-%d %H:%M:%S', level=logging.INFO)
logger = logging.getLogger(__name__)

class Solution:
    def racecar(self, target: int) -> int:
        pq = []
        pq.append([0, 0, 1])
        dist = defaultdict(lambda:defaultdict(lambda:float('inf')))
        dist[0][1] = 0
        while(pq):
            cost, x, speed = heapq.heappop(pq)
            if x == target:
                return cost
            if x+speed >= 0 and x+speed < 2*target+1 and dist[x+speed][speed*2] > cost+1:
                dist[x+speed][speed*2] = cost+1
                heapq.heappush(pq, [cost+1, x+speed, speed*2])
            if speed > 0 and dist[x][-1] > cost+1:
                dist[x][-1] = cost+1
                heapq.heappush(pq, [cost+1, x, -1])
            if speed < 0 and dist[x][1] > cost+1:
                dist[x][1] = cost+1
                heapq.heappush(pq, [cost+1, x, 1])           
        return 0
    
    def slove2(self, target: int) -> int:
        dp = [math.inf] * (target+3)
        dp[0] = 0
        for i in range(1, target+1):
            forward_step = 1
            while (1<<forward_step)-1 < 2*i:
                forward_distance = (1<<forward_step)-1
                if (forward_distance == i):
                    dp[i] = forward_step
                    break 
                elif (forward_distance > i):
                    dp[i] = min(dp[i], forward_step + 1 + dp[for])    
            
        
    
s = Solution()
logger.info(s.racecar(3))
logger.info(s.racecar(6))