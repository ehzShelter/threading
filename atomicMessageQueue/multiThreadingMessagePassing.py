import threading
import queue


# two seperate queue
counterQueue = queue.Queue()
printQueue = queue.Queue()

# independent counterManager thread execution unit


def counterManager():
    'I have EXCLUSIVE rights to update the counter variable'
    counter = 0

    while True:
        increment = counterQueue.get()
        counter += increment
        printQueue.put([
            'The count is %d' % counter,
            '---------------'])
        counterQueue.task_done()


counterManagerThreadObj = threading.Thread(target=counterManager)
# print(counterManagerThreadObj.isDaemon())
counterManagerThreadObj.daemon = True
counterManagerThreadObj.start()
# print(counterManagerThreadObj.isDaemon())
del counterManagerThreadObj


# independent printManagerThread thread execution unit


def printManager():
    'I have EXCLUSIVE rights to call the "print" keyword'

    while True:
        # block=True
        job = printQueue.get()
        for line in job:
            print(line)
        printQueue.task_done()


printManagerThread = threading.Thread(target=printManager)
printManagerThread.daemon = True
printManagerThread.start()
del printManagerThread


# independent worker thread execution unit
# Non-daemon Thread


def worker():
    'My job is to increment the counter and print the current count'
    counterQueue.put(1)


printQueue.put(['Starting up'])
workerThreadsList = []
for i in range(10):
    work = threading.Thread(target=worker)
    workerThreadsList.append(work)
    work.start()
for t in workerThreadsList:
    # Directly thread has been joined because not a daemon thread
    t.join()

counterQueue.join()
printQueue.put(['Finishing up'])
printQueue.join()
