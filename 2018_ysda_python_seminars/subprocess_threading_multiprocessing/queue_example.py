# see https://www.youtube.com/watch?v=Bv25Dwe84g0 (for full understanding)
import threading
import queue


class Counter:
    def __init__(self, value):
        self.value = value


def printer(printing_queue):
    while True:
        value = printing_queue.get()
        print(value)
        printing_queue.task_done()


def calculator(counter, calculation_queue, printing_queue):
    while True:
        delta = calculation_queue.get()
        counter.value += delta
        printing_queue.put(counter.value)
        calculation_queue.task_done()


def delta_generator(calculation_queue):
    calculation_queue.put(1)


def main():
    printing_queue = queue.Queue()
    printer_daemon = threading.Thread(
        target=printer,
        args=(printing_queue,),
        daemon=True
    )
    printer_daemon.start()

    counter = Counter(0)
    calculation_queue = queue.Queue()
    calculator_daemon = threading.Thread(
        target=calculator,
        args=(counter, calculation_queue, printing_queue),
        daemon=True
    )
    calculator_daemon.start()

    workers = [
        threading.Thread(target=delta_generator, args=(calculation_queue,))
        for _ in range(10)
    ]
    for worker in workers:
        worker.start()
    for worker in workers:
        worker.join()

    calculation_queue.join()
    printing_queue.join()


if __name__ == '__main__':
    main()
