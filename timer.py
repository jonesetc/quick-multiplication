'''
A simple script to run my program 10,000 times and time it.
'''

from time import time
import random

import numpy
import sh
from sh import echo

if __name__ == '__main__':
    inputs = []
    times = []
    command = sh.Command('./alu')

    for _ in xrange(10000):
        operator  =  '/' if random.random() < .5 else '*'
        operand1 = str(random.randint(1, 32768))
        operand2 = str(random.randint(1, 32768))
        inputs.append(' '.join([operator, operand1, operand2]))

    for i in inputs:
        begin_time = time()
        command(echo(i))
        end_time = time()
        times.append(end_time - begin_time)

    print 'Average execution time: %s' % (numpy.average(times))
    print 'Standard deviation in execution time: %s' % (numpy.std(times))
    print 'Minimum execution time: %s' % (min(times))
    print 'Maximum execution time: %s' % (max(times))