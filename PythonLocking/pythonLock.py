import threading

counterLock = threading.Lock()
printerLock = threading.Lock()

counter = 0


def worker():
    global counter
    with counterLock:
        counter += 1
        with printerLock:
            print('The count is %d' % counter)
            print('---------------')


with printerLock:
    print('Starting Up')


workerThreadsList = []
for i in range(10):
    work = threading.Thread(target=worker)
    workerThreadsList.append(work)
    work.start()

for t in workerThreadsList:
    t.join()

with printerLock:
    print('Finishing Up')
